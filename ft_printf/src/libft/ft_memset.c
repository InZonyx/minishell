/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:10:45 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:48 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fills the first 'len' bytes of the memory area pointed to by 's' with
 * the constant byte value 'c'.
 * Param. #1 Pointer to the memory area to fill.
 * Param. #2 The byte value to set, passed as an int and converted to 
 * unsigned char.
 * Param. #3 Number of bytes to set.
 * Return value The original pointer 's'.
 */

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}
