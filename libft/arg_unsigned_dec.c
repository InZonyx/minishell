/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_unsigned_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:00:46 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/30 14:47:48 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arg_unsigned_dec(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, "0123456789"));
}
