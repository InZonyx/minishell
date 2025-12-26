/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:21:54 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:25 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes the character 'c' to the file descriptor 'fd'.
 * Param. #1 The character to output.
 * Param. #2 The file descriptor on which to write.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
