/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:12:01 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:25:20 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_format *fmt)
{
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_space = 0;
	fmt->flag_plus = 0;
	fmt->flag_width_star = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = 0;
	return ;
}

int	ft_parse_flags_char(const char *format, t_format *fmt)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0' || format[i] == '#'
		|| format[i] == ' ' || format[i] == '+')
	{
		if (format[i] == '-')
			fmt->flag_minus = 1;
		else if (format[i] == '0')
			fmt->flag_zero = 1;
		else if (format[i] == '#')
			fmt->flag_hash = 1;
		else if (format[i] == ' ')
			fmt->flag_space = 1;
		else if (format[i] == '+')
			fmt->flag_plus = 1;
		i++;
	}
	return (i);
}

int	ft_parse_width(const char *format, t_format *fmt, int i)
{
	if (format[i] == '*')
	{
		fmt->flag_width_star = 1;
		i++;
	}
	else
		while (format[i] >= '0' && format[i] <= '9')
			fmt->width = fmt->width * 10 + (format[i++] - '0');
	return (i);
}

int	ft_parse_precision(const char *format, t_format *fmt, int i)
{
	if (format[i] == '.')
	{
		i++;
		fmt->precision = 0;
		while (format[i] >= '0' && format[i] <= '9')
			fmt->precision = fmt->precision * 10 + (format[i++] - '0');
	}
	return (i);
}
