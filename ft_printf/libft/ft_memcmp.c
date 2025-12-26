/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:22:50 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:22 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first 'n' bytes of the memory areas 's1' and 's2'.
 * Param. #1 Pointer to the first memory area.
 * Param. #2 Pointer to the second memory area.
 * Param. #3 Number of bytes to compare.
 * Return value An integer less than, equal to, or greater than zero if 's1'
 * is found, respectively, to be less than, to match, or be greater than 's2'.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *) s1;
	src2 = (unsigned char *) s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}
