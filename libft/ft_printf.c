/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:09:56 by amoureau          #+#    #+#             */
/*   Updated: 2025/10/30 14:47:38 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert(char str, va_list *ap)
{
	int	count;

	count = 0;
	if (str == '%')
		count += arg_char('%');
	else if (str == 'c')
		count = arg_char(va_arg(*ap, int));
	else if (str == 's')
		count = arg_string(va_arg(*ap, const char *));
	else if (str == 'p')
		count = arg_voidp(va_arg(*ap, uintptr_t));
	else if (str == 'd' || str == 'i')
		count = arg_integer(va_arg(*ap, int));
	else if (str == 'u')
		count = arg_unsigned_dec(va_arg(*ap, unsigned int));
	else if (str == 'x' || str == 'X')
		count = arg_hex(va_arg(*ap, unsigned int), str);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		count;
	char	*str;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, input);
	str = ft_strdup(input);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += convert(str[i], &ap);
		}
		else
			count += arg_char(str[i]);
		i++;
	}
	va_end(ap);
	free(str);
	return (count);
}
