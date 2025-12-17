/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:49:26 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/07 14:04:34 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	n;	
	unsigned int	b;
	size_t			x;
	size_t			y;

	if ((!dest || !src) && size == 0)
		return (0);
	n = 0;
	b = 0;
	x = (ft_strlen(src));
	y = (ft_strlen(dest));
	while (dest[n])
	{
		n++;
	}
	if (size <= y || size == 0)
		return (size + x);
	while (src[b] && n < size - 1)
	{
		dest[n] = src[b];
		n++;
		b++;
	}
	dest[n] = '\0';
	return (x + y);
}
