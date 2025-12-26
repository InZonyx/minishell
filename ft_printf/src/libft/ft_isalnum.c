/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:11:13 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:40 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if 'c' is an alphanumeric character (letter or digit).
 * Param. #1 The character code to check.
 * Return value 1 if alphanumeric; otherwise 0.
 */

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
