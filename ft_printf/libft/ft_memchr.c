/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:58 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:41 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Scans the initial 'n' bytes of the memory area pointed to by 's' for the
 * first instance of the byte 'c'.
 * Param. #1 Pointer to the memory area to scan.
 * Param. #2 The byte to search for (passed as an int, converted to unsigned 
 * char).
 * Param. #3 Number of bytes to examine.
 * Return value A pointer to the matching byte, or NULL if not found within 
 * 'n' bytes.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return (src + i);
		i++;
	}
	return (NULL);
}
