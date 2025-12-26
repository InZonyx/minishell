/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:00:17 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:29:40 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates sufficient memory for a copy of the string 's', does the copy,
 * and returns a pointer to it.
 * Param. #1 The string to duplicate.
 * Return value A pointer to the duplicated string, or NULL if allocation fails.
 */

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
