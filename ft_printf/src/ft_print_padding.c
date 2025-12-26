/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:21:05 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:29:22 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_left_padding(int padding, t_format *fmt)
{
	if (!fmt->flag_minus && padding > 0)
		if (fmt->precision >= 0 || !fmt->flag_zero)
			return (ft_print_padding(' ', padding));
	return (0);
}

int	ft_print_right_padding(int padding, t_format *fmt)
{
	if (fmt->flag_minus && padding > 0)
		return (ft_print_padding(' ', padding));
	return (0);
}

int	ft_print_zero_padding(int padding, t_format *fmt)
{
	if (!fmt->flag_minus && fmt->flag_zero && fmt->precision < 0 && padding > 0)
		return (ft_print_padding('0', padding));
	return (0);
}

int	ft_print_padding(char c, int count)
{
	int	len;

	len = 0;
	while (count > 0)
	{
		len += ft_print_c(c);
		count--;
	}
	return (len);
}

int	ft_print_number_body(int nb, t_format *fmt, char *num_str, int num_len)
{
	int	len;

	len = 0;
	if (fmt->precision == 0 && nb == 0)
		return (0);
	if (fmt->precision > num_len)
		len += ft_print_zeros(fmt->precision - num_len);
	if (nb < 0)
		len += ft_print_s(num_str + 1);
	else
		len += ft_print_s(num_str);
	return (len);
}
