/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:58:59 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 21:30:57 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Computes the number of characters needed to represent integer 'n' as a
 * string, including the sign for negative values and the terminating null byte.
 * Param. #1 The integer to measure.
 * Return value The length required to store the string representation.
 */

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

/**
 * Allocates (with malloc) and returns a string representing the integer 'n'.
 * Negative numbers are handled, including INT_MIN via long promotion.
 * Param. #1 The integer to convert.
 * Return value The string representing the integer, or NULL if allocation fails.
 */

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	num;

	num = n;
	length = get_num_length(n);
	str = (char *) malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--length] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
