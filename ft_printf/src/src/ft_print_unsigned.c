/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:56:42 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 18:27:47 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_num_length(unsigned int n, int base_length)
{
	int	length;

	length = 0;
	if (n == 0)
		length++;
	while (n != 0)
	{
		n /= base_length;
		length++;
	}
	return (length);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		length;
	long	num;

	num = n;
	length = ft_get_num_length(n, 10);
	str = (char *) malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--length] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

static int	ft_calculate_unsigned_padding(int num_len, t_format *fmt,
		int *total_width, unsigned int nb)
{
	if (fmt->precision == 0 && nb == 0)
		*total_width = 0;
	else
		*total_width = num_len;
	if (fmt->precision > num_len)
		*total_width = fmt->precision;
	if (fmt->width > *total_width)
		return (fmt->width - *total_width);
	return (0);
}

int	ft_print_unsigned_with_padding(unsigned int nb, t_format *fmt)
{
	char	*num_str;
	int		num_len;
	int		total_width;
	int		padding;
	int		result;

	result = 0;
	num_str = ft_unsigned_itoa(nb);
	num_len = ft_strlen(num_str);
	padding = ft_calculate_unsigned_padding(num_len, fmt, &total_width, nb);
	if (!fmt->flag_minus && padding > 0)
	{
		if (fmt->precision >= 0 || !fmt->flag_zero)
			result += ft_print_padding(' ', padding);
		else
			result += ft_print_padding('0', padding);
	}
	if (fmt->precision >= 0)
		result += ft_print_zeros(fmt->precision - num_len);
	if (!(fmt->precision == 0 && nb == 0))
		result += ft_print_s(num_str);
	if (fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	free(num_str);
	return (result);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		size;
	char	*num_str;

	size = 0;
	num_str = ft_unsigned_itoa(nb);
	size += ft_print_s(num_str);
	free(num_str);
	return (size);
}
