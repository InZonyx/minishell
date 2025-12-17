/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:24:35 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/02 11:35:16 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	x;
	int	c;
	int	s;

	s = 1;
	c = 0;
	x = 0;
	while (nptr[c] == 32 || (nptr[c] >= 9 && nptr[c] <= 13))
		c++;
	if (nptr[c] == 45 || nptr[c] == 43)
	{
		if (nptr[c] == 45)
			s *= -1;
		c++;
	}
	while (nptr[c] >= 48 && nptr[c] <= 57)
	{
		x = x * 10 + (nptr[c] - 48);
		c++;
	}
	return (x * s);
}
