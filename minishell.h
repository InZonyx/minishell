/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:49:06 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 16:39:01 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	int last_status;
	char **envp;
	char **token;
}   t_shell;

typedef struct s_cmd
{
	char	*cmd;
	char	*args;
}				t_cmd;


/* token */
void	tokenise(t_shell *sh, const char *line);

/* init / destroy */
int		shell_init(t_shell *sh);
void	shell_destroyer(t_shell *sh);

/* prompt loop utils */
int		is_only_spaces(const char *line);
void	handle_eof(t_shell *sh);
void	main_loop(t_shell *sh);

/* signals */
void	set_signals_prompt(void);
void	set_signals_parent_exec(void);
void	set_signals_child_exec(void);

/* processing */
void	process_line(t_shell *sh, const char *line);

/* small utils */
void	*xcalloc(size_t n, size_t s);
char	*xstrdup(const char *s);

/* tests */
void	read_line(void);
void	print_line(char *line);

#endif