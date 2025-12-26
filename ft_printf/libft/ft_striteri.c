/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:41:49 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:49 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function 'f' to each character of the string 's', passing its
 * index as first argument and the address of the character as second. Each
 * character is modified in place if 'f' changes it.
 * Param. #1 The string to iterate over.
 * Param. #2 The function to apply to each character by reference.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
