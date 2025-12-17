/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:06:33 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/17 10:06:22 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void read_line(void)
{
	char	*line;

	line = readline("$> ");
	print_line(line);
}

void print_line(char *line)
{
	printf("%s\n", line);
	free(line);
	read_line();
}
