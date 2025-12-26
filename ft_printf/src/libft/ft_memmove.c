/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:42:26 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:26 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'len' bytes from memory area 'src' to memory area 'dst'. The memory
 * areas may overlap; copying is done in a safe order to avoid corruption.
 * Param. #1 Destination buffer pointer.
 * Param. #2 Source buffer pointer.
 * Param. #3 Number of bytes to copy.
 * Return value The original pointer 'dst'.
 */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s)
		return (dst);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
