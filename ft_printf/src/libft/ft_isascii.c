/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:12:48 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:44 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if 'c' is a 7-bit ASCII character (in the range 0 to 127).
 * Param. #1 The character code to check.
 * Return value 1 if ASCII; otherwise 0.
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
