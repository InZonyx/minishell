/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:48:49 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 18:28:19 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	parse_cmd_words(t_token **current, t_cmd *cmd)
{
	int		count;
	char	**argv;
	t_token	*start;

	count = 0;
	start = *current;
	while (*current && (*current)->type == TOK_WORD)
	{
		count++;
		*current = (*current)->next;
	}
	if (count == 0)
		return (0);
	argv = xcalloc(count + 1, sizeof(char *));
	*current = start;
	count = 0;
	while (*current && (*current)->type == TOK_WORD)
	{
		argv[count++] = (*current)->value;
		*current = (*current)->next;
	}
	argv[count] = NULL;
	cmd->argv = argv;
	return (1);
}

static int	parse_cmd_redirs(t_token **current, t_cmd *cmd)
{
	t_redir	*redir;

	while (*current && (*current)->type != TOK_PIPE)
	{
		if ((*current)->type == TOK_WORD)
		{
			*current = (*current)->next;
			continue ;
		}
		if (!(*current)->next || (*current)->next->type != TOK_WORD)
			return (-1);
		redir = new_redir((*current)->type, (*current)->next->value);
		add_cmd_redir(&cmd->redirs, redir);
		*current = (*current)->next->next;
	}
	return (1);
}

static t_cmd	*parse_single_cmd(t_token **current)
{
	t_cmd	*cmd;

	cmd = xcalloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	if (!parse_cmd_words(current, cmd))
	{
		free(cmd);
		return (NULL);
	}
	if (parse_cmd_redirs(current, cmd) == -1)
	{
		free_cmd(cmd);
		return (NULL);
	}
	return (cmd);
}

t_cmd	*parse(t_token *tokens)
{
	t_cmd	*cmd_list;
	t_cmd	*new_cmd;
	t_token	*current;

	if (!tokens || !check_syntax_errors(tokens))
		return (NULL);
	cmd_list = NULL;
	current = tokens;
	while (current)
	{
		new_cmd = parse_single_cmd(&current);
		if (!new_cmd)
			return (free_cmd(cmd_list), NULL);
		add_cmd(&cmd_list, new_cmd);
		if (!current || current->type != TOK_PIPE)
			break ;
		current = current->next;
	}
	return (cmd_list);
}
