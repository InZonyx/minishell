/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:17 by amoureau          #+#    #+#             */
/*   Updated: 2025/09/30 16:16:13 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		n;
	size_t	x;

	if ((!big || !little) && len == 0)
		return (0);
	x = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[x] != '\0' && x < len)
	{
		n = 0;
		while (big[n + x] == little[n] && (x + n) < len)
		{
			if (little[n + 1] == '\0')
				return ((char *)&big[x]);
			n++;
		}
		x++;
	}
	return (0);
}
