/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:25:56 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 17:07:08 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_only_spaces(const char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != 32 || (line[i] >= 8 && line[i] <= 12))
			return (0);
		i++;
	}
	return (1);
}

void	shell_destroyer(t_shell *sh)
{
	if (!sh)
		return ;
	if (sh->tokens)
	{
		free_tokens(sh->tokens);
		sh->tokens = NULL;
	}
	if (sh->cmd)
	{
		free_cmd(sh->cmd);
		sh->cmd = NULL;
	}
	if (sh->env)
	{
		env_free(sh->env);
		sh->env = NULL;
	}
	rl_clear_history();
}
