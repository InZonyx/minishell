/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:23:26 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/29 14:42:52 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *buf)
{
	char	*temp;
	char	*temp2;
	int		char_read;

	char_read = 1;
	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (char_read >= 1)
	{
		char_read = read(fd, temp, BUFFER_SIZE);
		if (char_read == -1)
			return (free(temp), free(buf), NULL);
		temp[char_read] = 0;
		temp2 = buf;
		buf = ft_strjoin(buf, temp);
		free(temp2);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(temp);
	return (buf);
}

static char	*get_line(char *buf)
{
	int		i;
	char	*line;

	if (!buf || !buf[0])
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*del_line(char *buf)
{
	int		i;
	int		count;
	char	*temp;

	temp = buf;
	i = 0;
	count = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
		return (free(temp), NULL);
	i++;
	buf = ft_calloc(ft_strlen(&temp[i]) + 1, sizeof(char));
	while (temp[count + i])
	{
		buf[count] = temp[count + i];
		count++;
	}
	free(temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[1023];
	char		*line;

	if (fd < 0 || fd > 1023)
		return (0);
	buf[fd] = read_file(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = get_line(buf[fd]);
	buf[fd] = del_line(buf[fd]);
	return (line);
}
