/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:25:24 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:23 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dst'. The memory
 * areas must not overlap; use ft_memmove if they do.
 * Param. #1 Destination buffer pointer.
 * Param. #2 Source buffer pointer.
 * Param. #3 Number of bytes to copy.
 * Return value The original pointer 'dst'. Returns NULL if both 'dst' and
 * 'src' are NULL.
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}
