/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:22:12 by elhirond          #+#    #+#             */
/*   Updated: 2025/12/28 19:55:38 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	shell_init(t_shell *sh, char **envp)
{
	if (!sh)
		return (1);
	sh->last_status = 0;
	sh->tokens = NULL;
	sh->cmd = NULL;
	sh->envp = envp;
	sh->env = env_init(envp);
	if (envp && *envp && !sh->env)
		return (1);
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
	if (sh->tokens)
		free_tokens(sh->tokens);
	if (sh->cmd)
		free_cmd(sh->cmd);
	sh->tokens = NULL;
	sh->cmd = NULL;
	sh->tokens = lexer(line);
	if (!sh->tokens)
		return (1);
	// print_tokens(sh); //test - not final
	sh->cmd = parse(sh->tokens);
	if (!sh->cmd)
		return (1);
	return (execute(sh));
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
