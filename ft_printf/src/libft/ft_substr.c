/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:18:43 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:05 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a substring from the string 's'. The substring begins
 * at index 'start' and is of maximum size 'len'. If 'start' is greater than
 * the length of 's', an empty string is returned.
 * Param. #1 The input string from which to create the substring.
 * Param. #2 The start index of the substring in 's'.
 * Param. #3 The maximum length of the substring.
 * Return value The substring, or NULL if the allocation fails.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
