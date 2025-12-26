/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:49:06 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/26 18:35:59 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
    int last_status;
}   t_shell;

void read_line(void);
void print_line(char *line);

#endif