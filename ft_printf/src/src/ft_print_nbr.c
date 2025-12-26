/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:42:16 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 18:27:46 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zeros(int count)
{
	int	len;

	len = 0;
	while (count > 0)
	{
		len += ft_print_c('0');
		count--;
	}
	return (len);
}

int	ft_calculate_total_width(int nb, t_format *fmt, int num_len)
{
	int	total_width;
	int	sign_width;

	sign_width = 0;
	if (nb < 0 || fmt->flag_plus || fmt->flag_space)
		sign_width = 1;
	if (fmt->precision == 0 && nb == 0)
		total_width = sign_width;
	else if (fmt->precision > num_len)
		total_width = fmt->precision + sign_width;
	else
		total_width = num_len + sign_width;
	return (total_width);
}

int	ft_print_nbr_with_flags(int nb, t_format *fmt)
{
	char	*num_str;
	int		len;
	int		num_len;
	int		total_width;
	int		padding;

	len = 0;
	num_str = ft_itoa(nb);
	if (nb < 0)
		num_len = ft_strlen(num_str) - 1;
	else
		num_len = ft_strlen(num_str);
	total_width = ft_calculate_total_width(nb, fmt, num_len);
	padding = fmt->width - total_width;
	len += ft_print_left_padding(padding, fmt);
	len += ft_print_prefix_sign(nb, fmt);
	len += ft_print_zero_padding(padding, fmt);
	len += ft_print_number_body(nb, fmt, num_str, num_len);
	len += ft_print_right_padding(padding, fmt);
	free(num_str);
	return (len);
}

int	ft_print_nbr(int nb, t_format *fmt)
{
	if (!fmt)
		return (ft_print_nbr_basic(nb));
	return (ft_print_nbr_with_flags(nb, fmt));
}

int	ft_print_nbr_basic(int nb)
{
	int		len;
	char	*num_str;

	len = 0;
	num_str = ft_itoa(nb);
	len = ft_print_s(num_str);
	free(num_str);
	return (len);
}
