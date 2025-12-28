#include "../../minishell.h"

void	exec_child(t_exec_ctx *ctx, t_cmd *cmd, int fd_in, int fd_out);

static void	close_prev(int *prev_in)
{
	if (*prev_in != -1)
	{
		close(*prev_in);
		*prev_in = -1;
	}
}

static int	open_pipe_if_needed(t_cmd *cur, int *pipefd)
{
	if (cur->next)
	{
		if (pipe(pipefd) == -1)
		{
			perror("minishell: pipe");
			return (1);
		}
	}
	else
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	return (0);
}

static int	start_child(t_exec_ctx *ctx, t_cmd *cur, int prev_in, int *pipefd)
{
	pid_t	pid;
	int		out_fd;

	pid = fork();
	if (pid == -1)
		return (perror("minishell: fork"), -1);
	if (pid == 0)
	{
		out_fd = -1;
		if (cur->next)
		{
			close(pipefd[0]);
			out_fd = pipefd[1];
		}
		exec_child(ctx, cur, prev_in, out_fd);
	}
	return ((int)pid);
}

static pid_t	run_pipeline(t_exec_ctx *ctx)
{
	t_cmd	*cur;
	int		pipefd[2];
	int		prev_in;
	pid_t	pid;

	prev_in = -1;
	cur = ctx->sh->cmd;
	pid = -1;
	while (cur)
	{
		if (open_pipe_if_needed(cur, pipefd))
			return (-1);
		pid = start_child(ctx, cur, prev_in, pipefd);
		if (pid == -1)
			return (-1);
		if (cur->next)
			close(pipefd[1]);
		close_prev(&prev_in);
		if (cur->next)
			prev_in = pipefd[0];
		cur = cur->next;
	}
	return (pid);
}

int	execute(t_shell *sh)
{
	t_exec_ctx	ctx;
	pid_t		pid;
	int			status;

	if (!sh || !sh->cmd || !sh->cmd->argv || !sh->cmd->argv[0])
		return (0);
	if (!sh->cmd->next && is_builtin(sh->cmd->argv[0]))
		return (exec_builtin_parent(sh, sh->cmd));
	ctx.sh = sh;
	ctx.envp_arr = env_to_array(sh->env);
	if (!ctx.envp_arr)
		return (sh->last_status = 1);
	set_signals_parent_exec();
	pid = run_pipeline(&ctx);
	free_strarray(ctx.envp_arr);
	status = wait_all(pid);
	set_signals_prompt();
	sh->last_status = status;
	return (status);
}
