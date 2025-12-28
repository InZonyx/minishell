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

static int	redir_in(const char *target)
{
	int	fd;

	fd = open_target(TOK_REDIR_IN, target);
	if (fd < 0)
		return (perror(target), 1);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("minishell: dup2");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	redir_out(const char *target, enum e_token_type type)
{
	int	fd;

	fd = open_target(type, target);
	if (fd < 0)
		return (perror(target), 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("minishell: dup2");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	redir_heredoc(const char *delimiter)
{
	int	fd;

	fd = heredoc_read(delimiter);
	if (fd == -1)
		return (write(2, "minishell: heredoc error\n", 25), 1);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("minishell: dup2");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	apply_redirs(t_redir *redir)
{
	while (redir)
	{
		if (!redir->target)
			return (1);
		if (redir->type == TOK_REDIR_IN)
		{
			if (redir_in(redir->target))
				return (1);
		}
		else if (redir->type == TOK_REDIR_OUT || redir->type == TOK_APPEND)
		{
			if (redir_out(redir->target, redir->type))
				return (1);
		}
		else if (redir->type == TOK_HEREDOC)
		{
			if (redir_heredoc(redir->target))
				return (1);
		}
		redir = redir->next;
	}
	return (0);
}
