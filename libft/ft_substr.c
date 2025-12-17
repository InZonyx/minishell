/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:45:52 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/08 10:55:16 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*r;

	if (!s)
		return (0);
	if (start >= (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	x = 0;
	if ((len > (size_t)ft_strlen(s) - start))
		r = malloc(sizeof(char) * ((size_t)ft_strlen(s) - start + 1));
	else
		r = malloc((sizeof(char)) * (len + 1));
	if (!r)
		return (NULL);
	while (x < len && s[start + x])
	{
		r[x] = s[start + x];
		x++;
	}
	r[x] = '\0';
	return (r);
}
