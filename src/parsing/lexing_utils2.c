/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:35:27 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:46:27 by amoureau         ###   ########.fr       */
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

static int	get_word_len(const char *line, int i)
{
	int		len;
	char	quote;

	len = 0;
	while (line[i] && !is_space(line[i]) && !is_operator(line[i]))
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
			{
				len++;
				i++;
			}
			if (line[i] == quote)
				i++;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

/**
 * @brief Gets the word token
 * 
 * @param line from the user input
 * @param i position of first letter of word
 * @return * char* malloced word
 */
//this will glitch with quotes in quotes because len skips quotes but not getw
char	*get_word(const char *line, int *i)
{
	int		len;
	int		j;
	char	*word;
	char	quote;

	len = get_word_len(line, *i);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]))
	{
		if (line[*i] == '\'' || line[*i] == '"')
		{
			quote = line[(*i)++];
			while (line[*i] && line[*i] != quote)
				word[j++] = line[(*i)++];
			if (line[*i] == quote)
				(*i)++;
		}
		else
			word[j++] = line[(*i)++];
	}
	word[j] = '\0';
	return (word);
}

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
