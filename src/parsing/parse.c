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

// static int	parse_cmd_words(t_token **current, t_cmd *cmd)
// {
// 	int		count;
// 	char	**argv;
// 	t_token	*start;

// 	count = 0;
// 	start = *current;
// 	while (*current && (*current)->type == TOK_WORD)
// 	{
// 		count++;
// 		*current = (*current)->next;
// 	}
// 	if (count == 0)
// 		return (0);
// 	argv = xcalloc(count + 1, sizeof(char *));
// 	*current = start;
// 	count = 0;
// 	while (*current && (*current)->type == TOK_WORD)
// 	{
// 		argv[count++] = (*current)->value;
// 		*current = (*current)->next;
// 	}
// 	argv[count] = NULL;
// 	cmd->argv = argv;
// 	return (1);
// }

// static int	parse_cmd_words(t_token **current, t_cmd *cmd)
// {
// 	int		count;
// 	char	**argv;
// 	t_token	*start;

// 	count = 0;
// 	start = *current;
// 	while (*current && (*current)->type == TOK_WORD)
// 	{
// 		count++;
// 		*current = (*current)->next;
// 	}
// 	if (count == 0)
// 		return (0);
// 	argv = xcalloc(count + 1, sizeof(char *));
// 	if (!argv)
// 		return (0);
// 	*current = start;
// 	count = 0;
// 	while (*current && (*current)->type == TOK_WORD)
// 	{
// 		argv[count] = xstrdup((*current)->value);
// 		if (!argv[count])
// 			return (0);
// 		count++;
// 		*current = (*current)->next;
// 	}
// 	argv[count] = NULL;
// 	cmd->argv = argv;
// 	return (1);
// }

// static int	parse_cmd_redirs(t_token **current, t_cmd *cmd)
// {
// 	t_redir	*redir;

// 	while (*current && (*current)->type != TOK_PIPE)
// 	{
// 		if ((*current)->type == TOK_WORD)
// 		{
// 			*current = (*current)->next;
// 			continue ;
// 		}
// 		if (!(*current)->next || (*current)->next->type != TOK_WORD)
// 			return (-1);
// 		redir = new_redir((*current)->type, xstrdup((*current)->next->value));
// 		add_cmd_redir(&cmd->redirs, redir);
// 		*current = (*current)->next->next;
// 	}
// 	return (1);
// }

// static int	parse_cmd_redirs_start(t_token **current, t_cmd *cmd)
// {
// 	t_redir *redir;

// 	while (*current && (*current)->type != TOK_PIPE
// 			&& ((*current)->type == TOK_REDIR_IN
// 			|| (*current)->type == TOK_REDIR_OUT
// 			|| (*current)->type == TOK_APPEND
// 			|| (*current)->type == TOK_HEREDOC))
// 	{
// 		if (!(*current)->next || (*current)->next->type != TOK_WORD)
// 			return (-1);
// 		redir = new_redir((*current)->type, xstrdup((*current)->next->value));
// 		add_cmd_redir(&cmd->redirs, redir);
// 		*current = (*current)->next->next;
// 	}
// 	return (1);
// }

// static t_cmd	*parse_single_cmd(t_token **current)
// {
// 	t_cmd	*cmd;

// 	cmd = xcalloc(1, sizeof(t_cmd));
// 	if (!cmd)
// 		return (NULL);
// 	if (parse_cmd_redirs_start(current, cmd) == -1)
// 	{
// 		free(cmd);
// 		return (NULL);
// 	}
// 	if (!parse_cmd_words(current, cmd))
// 	{
// 		free(cmd);
// 		return (NULL);
// 	}
// 	if (parse_cmd_redirs(current, cmd) == -1)
// 	{
// 		free_cmd(cmd);
// 		return (NULL);
// 	}
// 	return (cmd);
// }

// static int	add_word_to_argv(t_cmd *cmd, const char *word)
// {
//     char	**new_argv;
//     int		count;

//     count = 0;
//     if (cmd->argv)
//     {
//         while (cmd->argv[count])
//             count++;
//     }
//     new_argv = xcalloc(count + 2, sizeof(char *));
//     if (!new_argv)
//         return (0);
//     count = 0;
//     if (cmd->argv)
//     {
//         while (cmd->argv[count])
//         {
//             new_argv[count] = cmd->argv[count];
//             count++;
//         }
//         free(cmd->argv);
//     }
//     new_argv[count] = xstrdup(word);
//     if (!new_argv[count])
//         return (0);
//     new_argv[count + 1] = NULL;
//     cmd->argv = new_argv;
//     return (1);
// }

// static t_cmd	*parse_single_cmd(t_token **current)
// {
//     t_cmd	*cmd;
//     t_redir	*redir;

//     cmd = xcalloc(1, sizeof(t_cmd));
//     if (!cmd)
//         return (NULL);
//     cmd->argv = xcalloc(1, sizeof(char *));
//     if (!cmd->argv)
//         return (free(cmd), NULL);
//     cmd->argv[0] = NULL;
	
//     while (*current && (*current)->type != TOK_PIPE)
//     {
//         if ((*current)->type == TOK_WORD)
//         {
//             if (!add_word_to_argv(cmd, (*current)->value))
//                 return (free_cmd(cmd), NULL);
//             *current = (*current)->next;
//         }
//         else if ((*current)->type == TOK_REDIR_IN 
//             || (*current)->type == TOK_REDIR_OUT
//             || (*current)->type == TOK_APPEND
//             || (*current)->type == TOK_HEREDOC)
//         {
//             if (!(*current)->next || (*current)->next->type != TOK_WORD)
//                 return (free_cmd(cmd), NULL);
//             redir = new_redir((*current)->type, xstrdup((*current)->next->value));
//             if (!redir)
//                 return (free_cmd(cmd), NULL);
//             add_cmd_redir(&cmd->redirs, redir);
//             *current = (*current)->next->next;
//         }
//         else
//         {
//             *current = (*current)->next;
//         }
//     }
//     if (!cmd->argv[0])
//         return (free_cmd(cmd), NULL);
//     return (cmd);
// }

static int	count_argv(char **argv)
{
	int	count;

	count = 0;
	if (argv)
		while (argv[count])
			count++;
	return (count);
}

static int	add_word_to_argv(t_cmd *cmd, const char *word)
{
	char	**new_argv;
	int		count;
	int		i;

	if (word[0] == '\0')
		return (1);
	count = count_argv(cmd->argv);
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
		return (0);
	new_argv[count + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
	return (1);
}

static int	handle_redir(t_cmd *cmd, t_token **current)
{
	t_redir *redir;

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
	t_cmd *cmd;
	if (!(cmd = xcalloc(1, sizeof(t_cmd))))
		return (NULL);
	if (!(cmd->argv = xcalloc(1, sizeof(char *))))
		return (free(cmd), NULL);
	while (*current && (*current)->type != TOK_PIPE)
	{
		if ((*current)->type == TOK_WORD)
		{
			if (!add_word_to_argv(cmd, (*current)->value))
				return (free_cmd(cmd), NULL);
			*current = (*current)->next;
		}
		else if ((*current)->type >= TOK_REDIR_IN && (*current)->type <= TOK_HEREDOC)
		{
			if (!handle_redir(cmd, current))
				return (free_cmd(cmd), NULL);
		}
		else
			*current = (*current)->next;
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
