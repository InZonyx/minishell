/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:13:45 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/08 11:18:40 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	int		x;

	x = 0;
	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r)
		return (0);
	while (s[x])
	{
		r[x] = s[x];
		x++;
	}
	r[x] = '\0';
	return (r);
}
