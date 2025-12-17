/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:15:01 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/08 10:42:43 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int		c;
	long	x;

	x = n;
	c = 0;
	if (x == 0)
		return (2);
	if (x < 0)
	{
		x *= -1;
		c++;
	}
	while (x > 0)
	{
		x /= 10;
		c++;
	}
	c++;
	return (c);
}

static void	charint(int nbr, char *res)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		res[1] = '\0';
	}
	if (n >= 10)
	{
		charint(n / 10, res);
		charint(n % 10, res);
	}
	else
	{
		res[ft_strlen(res) + 1] = '\0';
		res[ft_strlen(res)] = (n + '0');
	}
}

char	*ft_itoa(int n)
{
	char	*r;

	r = (char *)malloc(sizeof(char) * (len(n)));
	if (!r)
		return (0);
	r[0] = '\0';
	charint(n, r);
	return (r);
}
