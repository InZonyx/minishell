/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:23:21 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/29 14:47:20 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t;
	int		x;
	int		y;
	char	*r;

	if (!s1 || !s2)
		return (0);
	t = (ft_strlen(s1) + ft_strlen(s2));
	r = malloc(sizeof(char) * (t + 1));
	if (!r)
		return (0);
	x = 0;
	while (s1[x])
	{
		r[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y])
	{
		r[x + y] = s2[y];
		y++;
	}
	r[x + y] = '\0';
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&*s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)&*s);
	return (NULL);
}

