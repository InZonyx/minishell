/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:22:12 by elhirond          #+#    #+#             */
/*   Updated: 2025/12/29 16:10:20 by amoureau         ###   ########.fr       */
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

static void	handle_eof(t_shell *sh)
{
	// printf("exit\n");
	shell_destroyer(sh);
	exit(sh->last_status);
}

static int	all_empty_words(t_token *t)
{
	if (!t)
		return (0);
	while (t)
	{
		if (t->type != TOK_WORD)
			return (0);
		if (t->value && t->value[0] != '\0')
			return (0);
		t = t->next;
	}
	return (1);
}

static int	process_line(t_shell *sh, const char *line)
{
	if (!sh || !line)
		return (1);
	if (sh->tokens)
		free_tokens(sh->tokens);
	if (sh->cmd)
		free_cmd(sh->cmd);
	sh->tokens = NULL;
	sh->cmd = NULL;
	sh->tokens = lexer(sh, line);
	if (!sh->tokens)
		return (sh->last_status = 2, 1);
	sh->cmd = parse(sh->tokens);
	if (!sh->cmd)
	{
		if (all_empty_words(sh->tokens))
			return (sh->last_status = 0, 0);
		return (sh->last_status = 2, 1);
	}
	return (execute(sh));
}

// void	main_loop(t_shell *sh)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		set_signals_prompt();
// 		g_signal_received = 0;
// 		line = readline("minishell$ ");
// 		if (g_signal_received == SIGINT)
// 			sh->last_status = 130;
// 		if (line == NULL)
// 			handle_eof(sh);
// 		if (is_only_spaces(line))
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		add_history(line);
// 		process_line(sh, line);
// 		free(line);
// 	}
// }

/*   testing function to remove afterwards    */
void main_loop(t_shell *sh)
{
    char *line;

    while (1)
    {
        g_signal_received = 0;

        if (isatty(STDIN_FILENO))
        {
            set_signals_prompt();
            line = readline("minishell$ ");
        }
        else
        {
            line = get_next_line(STDIN_FILENO);
        }

        if (!line)
            handle_eof(sh);

        if (!isatty(STDIN_FILENO))
        {
            char *tmp = ft_strtrim(line, "\n");
            free(line);
            line = tmp;
        }

        if (g_signal_received == SIGINT)
            sh->last_status = 130;

        if (is_only_spaces(line))
        {
            free(line);
            continue;
        }

        if (isatty(STDIN_FILENO))
            add_history(line);

        process_line(sh, line);
        free(line);
    }
}
