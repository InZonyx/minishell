/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:05 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:02:08 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	lx_buf_init(char **buf, size_t *len, size_t *cap)
{
	*cap = 64;
	*len = 0;
	*buf = malloc(*cap);
	if (!*buf)
		return (1);
	(*buf)[0] = '\0';
	return (0);
}

int	lx_buf_grow(char **buf, size_t *cap, size_t need)
{
	char	*newbuf;
	size_t	newcap;

	if (*cap >= need)
		return (0);
	newcap = *cap;
	while (newcap < need)
		newcap *= 2;
	newbuf = malloc(newcap);
	if (!newbuf)
		return (1);
	ft_memcpy(newbuf, *buf, *cap);
	free(*buf);
	*buf = newbuf;
	*cap = newcap;
	return (0);
}

int	lx_buf_add_char(char **buf, size_t *len, size_t *cap, char c)
{
	if (lx_buf_grow(buf, cap, *len + 2))
		return (1);
	(*buf)[*len] = c;
	*len += 1;
	(*buf)[*len] = '\0';
	return (0);
}

int	lx_buf_add_str(char **buf, size_t *len, size_t *cap, const char *s)
{
	size_t	sl;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (lx_buf_grow(buf, cap, *len + sl + 1))
		return (1);
	ft_memcpy(*buf + *len, s, sl);
	*len += sl;
	(*buf)[*len] = '\0';
	return (0);
}

int	lx_buf_add_itoa(char **buf, size_t *len, size_t *cap, int n)
{
	char	*tmp;
	int		err;

	tmp = ft_itoa(n);
	if (!tmp)
		return (1);
	err = lx_buf_add_str(buf, len, cap, tmp);
	free(tmp);
	return (err);
}
