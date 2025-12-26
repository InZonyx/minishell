/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:13:46 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:29:50 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies up to 'size - 1' characters from the string 'src' to 'dst',
 * NUL-terminating the result if 'size' is not 0.
 * Param. #1 Destination buffer.
 * Param. #2 Source string.
 * Param. #3 Size of the destination buffer.
 * Return value The total length of the string it tried to create: length of
 * 'src'.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
