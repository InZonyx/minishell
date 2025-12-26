/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:29 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:05:16 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_format
{
	int		width;
	int		precision;
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		flag_width_star;
	char	specifier;
}				t_format;

int		ft_printf(const char *format, ...);
int		ft_dispatch(va_list ap, t_format *fmt);
int		ft_print_format_literal(const char *format, int len);

void	ft_init_flags(t_format *fmt);
int		ft_parse_flags_char(const char *format, t_format *fmt);
int		ft_parse_width(const char *format, t_format *fmt, int i);
int		ft_parse_precision(const char *format, t_format *fmt, int i);
int		ft_parse_flags(const char *format, t_format *fmt);

int		ft_print_c(int c);
int		ft_print_c_with_padding(int c, t_format *fmt);
int		ft_print_s(char *str);
int		ft_print_s_with_padding(char *str, t_format *fmt);
int		ft_putstr(char *str);

int		ft_print_nbr(int nb, t_format *fmt);
int		ft_print_nbr_basic(int nb);
int		ft_print_nbr_with_flags(int nb, t_format *fmt);
int		ft_print_number_body(int nb, t_format *fmt, char *num_str, int num_len);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_unsigned_with_padding(unsigned int nb, t_format *fmt);

int		ft_print_hexa_with_padding(unsigned int nb, t_format *fmt);
int		ft_print_hexa_basic(unsigned int num, char format);
void	ft_putnbr_hexa(unsigned int num, char format);
int		ft_print_hexa_prefix(t_format *fmt, unsigned int num);

int		ft_print_ptr(uintptr_t ptr);
int		ft_print_ptr_with_padding(uintptr_t ptr, t_format *fmt);

int		ft_print_percent_with_padding(t_format *fmt);

int		ft_print_zeros(int count);
int		ft_print_left_padding(int padding, t_format *fmt);
int		ft_print_right_padding(int padding, t_format *fmt);
int		ft_print_zero_padding(int padding, t_format *fmt);
int		ft_print_padding(char c, int count);
int		ft_get_num_length(unsigned int nb, int base_length);

int		ft_print_prefix_sign(int nb, t_format *fmt);

#endif