/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:31:23 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:06:30 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_width_star(va_list ap, t_format *fmt)
{
	if (fmt->flag_width_star)
	{
		fmt->width = va_arg(ap, int);
		if (fmt->width < 0)
		{
			fmt->flag_minus = 1;
			fmt->width = -fmt->width;
		}
	}
	return ;
}

int	ft_dispatch(va_list ap, t_format *fmt)
{
	ft_handle_width_star(ap, fmt);
	if (fmt->specifier == '%')
		return (ft_print_percent_with_padding(fmt));
	else if (fmt->specifier == 'i' || fmt->specifier == 'd')
		return (ft_print_nbr(va_arg(ap, int), fmt));
	else if (fmt->specifier == 's')
		return (ft_print_s_with_padding(va_arg(ap, char *), fmt));
	else if (fmt->specifier == 'c')
		return (ft_print_c_with_padding(va_arg(ap, int), fmt));
	else if (fmt->specifier == 'u')
		return (ft_print_unsigned_with_padding(va_arg(ap, unsigned int), fmt));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		return (ft_print_hexa_with_padding(va_arg(ap, unsigned int), fmt));
	else if (fmt->specifier == 'p')
		return (ft_print_ptr_with_padding((uintptr_t)va_arg(ap, void *), fmt));
	return (-1);
}

int	ft_parse_flags(const char *format, t_format *fmt)
{
	int	i;

	ft_init_flags(fmt);
	i = ft_parse_flags_char(format, fmt);
	i = ft_parse_width(format, fmt, i);
	i = ft_parse_precision(format, fmt, i);
	fmt->specifier = format[i];
	return (i);
}

static int	ft_handle_format_spec(va_list ap, const char *format,
		size_t *i, t_format *fmt)
{
	int	step;
	int	result;

	step = ft_parse_flags(&format[*i + 1], fmt);
	result = ft_dispatch(ap, fmt);
	if (result == -1)
	{
		result = ft_print_format_literal(&format[*i], step + 2);
		*i += step + 2;
	}
	else
		*i += step + 2;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	int			size;
	va_list		ap;
	t_format	fmt;

	size = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			size += ft_handle_format_spec(ap, format, &i, &fmt);
		else
			size += ft_print_c(format[i++]);
	}
	va_end(ap);
	return (size);
}
