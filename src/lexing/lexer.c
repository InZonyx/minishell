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
