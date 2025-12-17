/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:18:33 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/30 14:52:08 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_base_help(long long nbr, char *base, int *count)
{
	long	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		*count += 1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base_help(nbr / base_len, base, count);
		ft_putnbr_base_help(nbr % base_len, base, count);
	}
	else
	{
		ft_putchar(base[nbr]);
		*count += 1;
	}
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	count;

	count = 0;
	ft_putnbr_base_help(nbr, base, &count);
	return (count);
}
