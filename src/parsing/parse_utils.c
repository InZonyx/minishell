/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:48:08 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 17:26:02 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir	*new_redir(enum e_token_type type, char *target)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->target = target;
	redir->next = NULL;
	return (redir);
}

t_cmd	*new_cmd(t_redir *redir, char *value)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = (char **)malloc(sizeof(char *) * 3);
	cmd->argv[0] = value;
	cmd->argv[1] = NULL;
	cmd->argv[2] = NULL;
	cmd->redirs = redir;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd(t_cmd **head, t_cmd *new)
{
	t_cmd	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_redir	*redir_tmp;

	while (cmd)
	{
		tmp = cmd->next;
		free_strarray(cmd->argv);
		while (cmd->redirs)
		{
			redir_tmp = cmd->redirs->next;
			free(cmd->redirs->target);
			free(cmd->redirs);
			cmd->redirs = redir_tmp;
		}
		free(cmd);
		cmd = tmp;
	}
}

void	add_cmd_redir(t_redir **head, t_redir *new)
{
	t_redir	*current;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
}
