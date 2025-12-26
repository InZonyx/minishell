/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:24:55 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:57 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function 'f' to each character of the string 's' to create a
 * new string resulting from successive applications of 'f'. The function 'f'
 * is passed the index of each character as its first argument.
 * Param. #1 The string to map.
 * Param. #2 The function to apply to each character.
 * Return value The string created from the successive applications of 'f', or
 * NULL if allocation fails or inputs are NULL.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *) malloc((sizeof(char) * ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
