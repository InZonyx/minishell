/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:04:16 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/08 11:22:26 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_string(char const *s, char c)
{
	int	x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	return (x);
}

static int	num_word(char const *s, char c)
{
	int	x;
	int	w;

	x = 0;
	w = 0;
	while (s[x])
	{
		if (s[x] && s[x] != c)
			w++;
		while (s[x] && s[x] != c)
			x++;
		while (s[x] && s[x] == c)
			x++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		x;
	int		y;

	if (!s)
		return (NULL);
	y = 0;
	x = 0;
	strs = (char **)malloc(sizeof(char *) * (num_word(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[x])
	{
		while (s[x] && s[x] == c)
			x++;
		if (s[x] && s[x] != c)
		{
			strs[y] = ft_substr(s, x, len_string(&s[x], c));
			y++;
		}
		while (s[x] && s[x] != c)
			x++;
	}
	strs[y] = NULL;
	return (strs);
}
