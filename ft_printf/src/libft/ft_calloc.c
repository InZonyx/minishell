/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:34:34 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:38 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory for an array of 'count' elements of 'size' bytes each and
 * initializes all bytes in the allocated storage to zero. Detects size_t
 * overflow.
 * Param. #1 Number of elements to allocate.
 * Param. #2 Size in bytes of each element.
 * Return value Pointer to the allocated zero-initialized memory, or NULL on
 * allocation failure or overflow.
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size && size > ((size_t)-1) / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
