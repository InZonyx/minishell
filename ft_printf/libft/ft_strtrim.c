/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:44:07 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:40:02 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a copy of 's1' with the characters specified in 'set'
 * removed from the beginning and the end of the string.
 * Param. #1 The string to be trimmed.
 * Param. #2 The set of characters to trim.
 * Return value The trimmed string, or NULL if allocation fails or inputs 
 * are NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = (char *) malloc((end - start + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
