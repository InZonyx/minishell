/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:03:46 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:29:58 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first 'n' characters of the strings 's1' and 's2'.
 * Characters are compared as unsigned char values.
 * Param. #1 First string to compare.
 * Param. #2 Second string to compare.
 * Param. #3 Maximum number of characters to compare.
 * Return value An integer less than, equal to, or greater than zero if 's1'
 * is found, respectively, to be less than, to match, or be greater than 's2'.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
