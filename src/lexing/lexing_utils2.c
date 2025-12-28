/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:35:27 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 20:43:59 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Gets the operator token
 * 
 * @param line from the user input
 * @param i position of first letter of word
 * @return t_token* new token link
 */
t_token	*get_operator(const char *line, int *i)
{
	if (line[*i] == '|')
		return ((*i) += 1, new_token(TOK_PIPE, ft_strdup("|")));
	if (line[*i] == '<' && line[*i + 1] == '<')
		return ((*i) += 2, new_token(TOK_HEREDOC, ft_strdup("<<")));
	if (line[*i] == '>' && line[*i + 1] == '>')
		return ((*i) += 2, new_token(TOK_APPEND, ft_strdup(">>")));
	if (line[*i] == '<')
		return ((*i) += 1, new_token(TOK_REDIR_IN, ft_strdup("<")));
	if (line[*i] == '>')
		return ((*i) += 1, new_token(TOK_REDIR_OUT, ft_strdup(">")));
	return (NULL);
}

/**
 * @brief Gets the word token
 * 
 * @param line from the user input
 * @param i position of first letter of word
 * @return * char* malloced word
 */
//this will glitch with quotes in quotes because len skips quotes but not get

int	check_unclosed_quotes(const char *line)
{
	int		i;
	char	quote;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
				return (1);
		}
		i++;
	}
	return (0);
}
