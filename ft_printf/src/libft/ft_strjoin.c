/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:07:53 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:01:52 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of 's1' and 's2'.
 * If the allocation fails the function returns NULL.
 * If 's1' or 's2' is NULL, the function returns 's2' or 's1'.
 * Param. #1 The prefix string.
 * Param. #2 The suffix string.
 * Return value The new string or NULL if the allocation fails
 * or 's1' and 's2' is NULL.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}
