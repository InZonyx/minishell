#include "../../minishell.h"

static void	dup_io(int fd_in, int fd_out)
{
	if (fd_in != -1)
		dup2(fd_in, STDIN_FILENO);
	if (fd_out != -1)
		dup2(fd_out, STDOUT_FILENO);
	if (fd_in != -1)
		close(fd_in);
	if (fd_out != -1)
		close(fd_out);
}

static void	exec_external(t_exec_ctx *ctx, t_cmd *cmd)
{
	char	*path;

	path = resolve_path(ctx->sh, cmd->argv[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
		exit(127);
	}
	execve(path, cmd->argv, ctx->envp_arr);
	perror("minishell: execve");
	exit(126);
}

void	exec_child(t_exec_ctx *ctx, t_cmd *cmd, int fd_in, int fd_out)
{
	set_signals_child_exec();
	dup_io(fd_in, fd_out);
	if (apply_redirs(cmd->redirs))
		exit(1);
	if (cmd->argv && cmd->argv[0] && is_builtin(cmd->argv[0]))
		exit(exec_builtin(ctx->sh, cmd->argv));
	exec_external(ctx, cmd);
}
