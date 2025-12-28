#include "../../minishell.h"

static int	open_target(enum e_token_type type, const char *path)
{
	if (type == TOK_REDIR_IN)
		return (open(path, O_RDONLY));
	if (type == TOK_REDIR_OUT)
		return (open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (type == TOK_APPEND)
		return (open(path, O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (-2);
}

int	apply_redirs(t_redir *redir)
{
	int	fd;

	while (redir)
	{
		if (!redir->target)
			return (1);
		fd = open_target(redir->type, redir->target);
		if (fd == -2)
			return (write(2, "minishell: heredoc not implemented\n", 35), 1);
		if (fd < 0)
			return (perror(redir->target), 1);
		if (redir->type == TOK_REDIR_IN && dup2(fd, STDIN_FILENO) < 0)
			return (perror("minishell: dup2"), close(fd), 1);
		if (redir->type != TOK_REDIR_IN && dup2(fd, STDOUT_FILENO) < 0)
			return (perror("minishell: dup2"), close(fd), 1);
		close(fd);
		redir = redir->next;
	}
	return (0);
}
