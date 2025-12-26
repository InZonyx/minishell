/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:56:18 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:06:05 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned int num, char format)
{
	if (num >= 16)
		ft_putnbr_hexa(num / 16, format);
	if (num % 16 <= 9)
		ft_print_c((num % 16) + '0');
	else
	{
		if (format == 'x')
			ft_print_c((num % 16) - 10 + 'a');
		else
			ft_print_c((num % 16) - 10 + 'A');
	}
	return ;
}

int	ft_print_hexa_prefix(t_format *fmt, unsigned int num)
{
	if (fmt->flag_hash && num != 0)
	{
		if (fmt->specifier == 'x')
			return (ft_print_s("0x"));
		else if (fmt->specifier == 'X')
			return (ft_print_s("0X"));
	}
	return (0);
}

static void	ft_calculate_hexa_dimensions(unsigned int num, t_format *fmt,
		int *dimensions)
{
	dimensions[0] = ft_get_num_length(num, 16);
	if (fmt->precision == 0 && num == 0)
		dimensions[0] = 0;
	dimensions[1] = 0;
	if (fmt->flag_hash && num != 0)
		dimensions[1] = 2;
	dimensions[2] = dimensions[0];
	if (fmt->precision > dimensions[0])
		dimensions[2] = fmt->precision;
	dimensions[2] += dimensions[1];
	dimensions[3] = fmt->width - dimensions[2];
	return ;
}

int	ft_print_hexa_with_padding(unsigned int num, t_format *fmt)
{
	int	len;
	int	dims[4];

	len = 0;
	if (!fmt)
		return (ft_print_hexa_basic(num, 'x'));
	ft_calculate_hexa_dimensions(num, fmt, dims);
	if (!fmt->flag_minus && dims[3] > 0)
	{
		if (fmt->precision >= 0 || !fmt->flag_zero)
			len += ft_print_padding(' ', dims[3]);
		else
			len += ft_print_padding('0', dims[3]);
	}
	len += ft_print_hexa_prefix(fmt, num);
	if (fmt->precision >= 0)
		len += ft_print_zeros(fmt->precision - dims[0]);
	if (!(fmt->precision == 0 && num == 0))
	{
		ft_putnbr_hexa(num, fmt->specifier);
		len += dims[0];
	}
	if (fmt->flag_minus && dims[3] > 0)
		len += ft_print_padding(' ', dims[3]);
	return (len);
}

int	ft_print_hexa_basic(unsigned int num, char format)
{
	ft_putnbr_hexa(num, format);
	return (ft_get_num_length(num, 16));
}
