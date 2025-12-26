/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:22:12 by elhirond          #+#    #+#             */
/*   Updated: 2025/12/26 19:41:49 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	handle_eof(t_shell *sh)
{
	printf("exit\n");
	shell_destroyer(sh);
	exit(sh->last_status);
}

void	main_loop(t_shell *sh)
{
	char	*line;

	while (1)
	{
		// set_signal_mode_prompt();      // SIGINT => newline + redisplay, SIGQUIT ignore
		line = readline("minishell$ ");
		if (line == NULL)
			handle_eof(sh);
		if (is_only_spaces(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		// process_line(sh, line);
		free(line);
	}
}