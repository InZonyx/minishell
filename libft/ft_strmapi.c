/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:31 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/02 11:21:15 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*r;
	unsigned int		x;

	if (!s || !f)
		return (0);
	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r)
		return (0);
	x = 0;
	while (s[x])
	{
		r[x] = f(x, s[x]);
		x++;
	}
	r[x] = '\0';
	return (r);
}
