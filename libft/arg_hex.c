/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:31:54 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/30 14:48:04 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arg_hex(unsigned int nbr, char format)
{
	if (format == 'x')
		return (ft_putnbr_base(nbr, "0123456789abcdef"));
	return (ft_putnbr_base(nbr, "0123456789ABCDEF"));
}
