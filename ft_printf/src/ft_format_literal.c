/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_literal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:58:47 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:23:59 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format_literal(const char *format, int len)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (i < len)
		result += ft_print_c(format[i++]);
	return (result);
}
