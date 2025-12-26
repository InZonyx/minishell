/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:03:32 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:31 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts the initial portion of the string pointed to by 'str' to int.
 * Skips leading whitespace, handles an optional '+' or '-' sign, and then
 * processes consecutive digits.
 * Param. #1 The string to convert.
 * Return value The converted integer value. Behavior on overflow is
 * implementation-defined (undefined for this simplified version).
 */

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;
	size_t			i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
