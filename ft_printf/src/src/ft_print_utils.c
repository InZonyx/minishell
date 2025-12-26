/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:46:08 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/08 19:26:57 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_print_s(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	ft_print_prefix_sign(int nb, t_format *fmt)
{
	if (nb < 0)
		return (ft_print_c('-'));
	else if (fmt->flag_plus)
		return (ft_print_c('+'));
	else if (fmt->flag_space)
		return (ft_print_c(' '));
	return (0);
}

int	ft_print_percent_with_padding(t_format *fmt)
{
	(void)fmt;
	return (ft_print_c('%'));
}
