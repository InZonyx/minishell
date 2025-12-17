/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:20:33 by amoureau          #+#    #+#             */
/*   Updated: 2025/09/30 12:10:13 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		x;
	size_t	b;
	size_t	y;

	y = 0;
	b = size;
	x = 0;
	while (size > 1 && src[x] != '\0')
	{
		dst[x] = src[x];
		size--;
		x++;
	}
	if (b > 0)
	{
		dst[x] = '\0';
	}
	while (src[y])
	{
		y++;
	}
	return (y);
}
