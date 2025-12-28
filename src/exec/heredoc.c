/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:34 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:02:35 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_delim(const char *l, const char *d)
{
	size_t	ld;

	if (!l || !d)
		return (0);
	ld = ft_strlen(d);
	return (ft_strlen(l) == ld && ft_strncmp(l, d, ld) == 0);
}

static int	write_hd(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) < 0)
		return (1);
	if (write(fd, "\n", 1) < 0)
		return (1);
	return (0);
}

int	heredoc_read(const char *delimiter)
{
	int		pfd[2];
	char	*line;

	if (pipe(pfd) < 0)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (!line || is_delim(line, delimiter))
			break ;
		if (write_hd(pfd[1], line))
			return (free(line), close(pfd[0]), close(pfd[1]), -1);
		free(line);
	}
	free(line);
	close(pfd[1]);
	return (pfd[0]);
}
