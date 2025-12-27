/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:22:12 by elhirond          #+#    #+#             */
/*   Updated: 2025/12/27 22:46:27 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	shell_init(t_shell *sh)
{
	sh->last_status = 0;
	return (0);
}

void	handle_eof(t_shell *sh)
{
	printf("exit\n");
	shell_destroyer(sh);
	exit(sh->last_status);
}

int	process_line(t_shell *sh, const char *line)
{
	if (!sh || !line)
		return (1);
	sh->tokens = lexer(line);
	print_tokens(sh);
	return (0);
}

void	main_loop(t_shell *sh)
{
	char	*line;

	while (1)
	{
		set_signals_prompt();
		g_signal_received = 0;
		line = readline("minishell$ ");
		if (g_signal_received == SIGINT)
			sh->last_status = 130;
		if (line == NULL)
			handle_eof(sh);
		if (is_only_spaces(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		process_line(sh, line);
		free(line);
	}
}
