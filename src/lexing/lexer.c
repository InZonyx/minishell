/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:34:57 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 23:53:25 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_token	*new_token(enum e_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

static t_token	*get_operator(const char *line, int *i)
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

static int	check_unclosed_quotes(const char *line)
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

t_token	*lexer(t_shell *sh, const char *line)
{
	t_token	*tokens;
	t_token	*tok;
	int		i;

	if (check_unclosed_quotes(line))
		return (write(2, "minishell: unclosed quote\n", 26), NULL);
	tokens = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] && is_space(line[i]))
			i++;
		if (!line[i])
			break ;
		if (is_operator(line[i]))
			tok = get_operator(line, &i);
		else
			tok = new_token(TOK_WORD, get_word(sh, line, &i));
		if (!tok)
			return (free_tokens(tokens), NULL);
		add_token(&tokens, tok);
	}
	return (tokens);
}
