/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:32:55 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:29:31 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of character 'c' in the string 's'. The
 * terminating null byte is considered part of the string.
 * Param. #1 The string to search.
 * Param. #2 The character to find (passed as an int, converted to char).
 * Return value A pointer to the located character, or NULL if not found.
 */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
