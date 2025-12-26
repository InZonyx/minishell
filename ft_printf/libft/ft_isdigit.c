/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:09:48 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:46 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if 'c' is a decimal digit character (0-9).
 * Param. #1 The character code to check.
 * Return value 1 if 'c' is a digit; otherwise 0.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
