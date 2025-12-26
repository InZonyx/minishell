/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:43:05 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:03 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the last occurrence of character 'c' in the string 's'. The
 * terminating null byte is considered part of the string.
 * Param. #1 The string to search.
 * Param. #2 The character to find (passed as an int, converted to char).
 * Return value A pointer to the located character, or NULL if not found.
 */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
