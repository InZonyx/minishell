/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:14:14 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:49 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if 'c' is a printable character including space.
 * Param. #1 The character code to check.
 * Return value 1 if printable; otherwise 0.
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
