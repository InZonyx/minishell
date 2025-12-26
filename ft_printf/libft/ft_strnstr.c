/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:47:01 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:01 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of the null-terminated string 'needle' in the
 * string 'haystack', where not more than 'len' characters are searched.
 * Param. #1 The big string to search in.
 * Param. #2 The small string to find.
 * Param. #3 The maximum number of characters to search.
 * Return value A pointer to the first occurrence of 'needle' within the first
 * 'len' characters of 'haystack', or NULL if not found. If 'needle' is empty,
 * returns 'haystack'.
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
