/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:05:18 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:24:33 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string_content(char *str, int print_len, int *result)
{
	int	len;

	len = 0;
	while (len < print_len && str[len])
		*result += ft_print_c(str[len++]);
	return ;
}

static void	ft_handle_null_string(char **str, int *str_len, t_format *fmt)
{
	if (!*str)
	{
		if (fmt->precision >= 0 && fmt->precision < 6)
		{
			*str = "";
			*str_len = 0;
		}
		else
		{
			*str = "(null)";
			*str_len = 6;
		}
	}
	else
		*str_len = ft_strlen(*str);
	return ;
}

int	ft_print_s_with_padding(char *str, t_format *fmt)
{
	int	str_len;
	int	print_len;
	int	padding;
	int	result;

	ft_handle_null_string(&str, &str_len, fmt);
	print_len = str_len;
	if (fmt->precision >= 0 && fmt->precision < str_len)
		print_len = fmt->precision;
	padding = 0;
	if (fmt->width > print_len)
		padding = fmt->width - print_len;
	result = 0;
	if (!fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	ft_print_string_content(str, print_len, &result);
	if (fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	return (result);
}

int	ft_print_c_with_padding(int c, t_format *fmt)
{
	int	padding;
	int	result;

	padding = 0;
	if (fmt->width > 1)
		padding = fmt->width - 1;
	result = 0;
	if (!fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	result += ft_print_c(c);
	if (fmt->flag_minus && padding > 0)
		result += ft_print_padding(' ', padding);
	return (result);
}
