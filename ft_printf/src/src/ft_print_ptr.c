/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:24:24 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:06:19 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(uintptr_t nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex(uintptr_t nb)
{
	char	c;

	if (nb >= 16)
		ft_puthex(nb / 16);
	c = "0123456789abcdef"[nb % 16];
	write(1, &c, 1);
	return ;
}

static int	print_null_ptr(t_format *fmt)
{
	int	ptr_len;
	int	padding;
	int	result;

	ptr_len = 5;
	padding = 0;
	if (fmt->width > ptr_len)
		padding = fmt->width - ptr_len;
	result = 0;
	if (!fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	result += ft_putstr("(nil)");
	if (fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	return (result);
}

int	ft_print_ptr_with_padding(uintptr_t ptr, t_format *fmt)
{
	int	len;
	int	ptr_len;
	int	padding;
	int	result;

	if (ptr == 0)
		return (print_null_ptr(fmt));
	len = ft_hexlen(ptr);
	ptr_len = len + 2;
	padding = 0;
	if (fmt->width > ptr_len)
		padding = fmt->width - ptr_len;
	result = 0;
	if (!fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	write(1, "0x", 2);
	ft_puthex(ptr);
	result += ptr_len;
	if (fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	return (result);
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	count;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count = 2;
	write(1, "0x", 2);
	ft_puthex(ptr);
	count += ft_hexlen(ptr);
	return (count);
}
