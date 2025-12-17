/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_voidp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:13:39 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/30 14:47:53 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arg_voidp(uintptr_t nbr)
{
	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	return (ft_putnbr_base_count_voidp(nbr, "0123456789abcdef") + 2);
}

static void	ft_putnbr_base_voidp(uintptr_t nbr, char *base, int *count)
{
	uintptr_t	base_len;

	base_len = (uintptr_t)ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		*count += 1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base_voidp(nbr / base_len, base, count);
		ft_putnbr_base_voidp(nbr % base_len, base, count);
	}
	else
	{
		ft_putchar(base[nbr]);
		*count += 1;
	}
}

int	ft_putnbr_base_count_voidp(uintptr_t nbr, char *base)
{
	int	count;

	count = 0;
	ft_putnbr_base_voidp(nbr, base, &count);
	return (count);
}
