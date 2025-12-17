/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:11:21 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/02 09:43:19 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
