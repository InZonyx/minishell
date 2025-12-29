/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:48:49 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/29 00:08:24 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	add_word_to_argv(t_cmd *cmd, const char *word)
{
	char	**new_argv;
	int		count;
	int		i;

	if (!word || word[0] == '\0')
		return (1);
	count = 0;
	while (cmd->argv && cmd->argv[count])
		count++;
	new_argv = xcalloc(count + 2, sizeof(char *));
	if (!new_argv)
		return (0);
	i = 0;
	while (i < count)
	{
		new_argv[i] = cmd->argv[i];
		i++;
	}
	new_argv[count] = xstrdup(word);
	if (!new_argv[count])
		return (free(new_argv), 0);
	new_argv[count + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
	return (1);
}

static t_cmd	*cmd_init(void)
{
	t_cmd	*cmd;

	cmd = xcalloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = xcalloc(1, sizeof(char *));
	if (!cmd->argv)
		return (free(cmd), NULL);
	return (cmd);
}

static int	parse_token(t_cmd *cmd, t_token **current)
{
	t_redir	*redir;

	if ((*current)->type == TOK_WORD)
	{
		if (!add_word_to_argv(cmd, (*current)->value))
			return (0);
		*current = (*current)->next;
		return (1);
	}
	if ((*current)->type < TOK_REDIR_IN || (*current)->type > TOK_HEREDOC)
		return (*current = (*current)->next, 1);
	if (!(*current)->next || (*current)->next->type != TOK_WORD)
		return (0);
	redir = new_redir((*current)->type,
			xstrdup((*current)->next->value));
	if (!redir)
		return (0);
	add_cmd_redir(&cmd->redirs, redir);
	*current = (*current)->next->next;
	return (1);
}

static t_cmd	*parse_single_cmd(t_token **current)
{
	t_cmd	*cmd;

	cmd = cmd_init();
	if (!cmd)
		return (NULL);
	while (*current && (*current)->type != TOK_PIPE)
	{
		if (!parse_token(cmd, current))
			return (free_cmd(cmd), NULL);
	}
	if (!cmd->argv[0] && !cmd->redirs)
		return (free_cmd(cmd), NULL);
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
