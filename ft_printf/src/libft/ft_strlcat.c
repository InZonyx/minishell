/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:50:58 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:29:47 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenates the string 'src' to the end of 'dst', ensuring the total size
 * does not exceed 'size' (including the terminating null byte). The result is
 * always null-terminated if 'size' is greater than 0.
 * Param. #1 The destination buffer to append to.
 * Param. #2 The source string to append.
 * Param. #3 The full size of the destination buffer.
 * Return value The length of the string it tried to create: initial length of
 * 'dst' plus the length of 'src'. If 'size' <= initial 'dst' length, returns
 * 'size' + length of 'src'.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
