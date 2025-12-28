/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:33:23 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 17:06:52 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_syntax_errors(t_token *tokens)
{
	if (!tokens)
		return (1);
	if (tokens->type == TOK_PIPE)
		return (write(2, "syntax error: pipe at start\n", 29), 0);
	while (tokens)
	{
		if (tokens->type == TOK_PIPE && !tokens->next)
			return (write(2, "syntax error: pipe at end\n", 27), 0);
		if (tokens->type == TOK_PIPE && tokens->next->type == TOK_PIPE)
			return (write(2, "syntax error: double pipe\n", 27), 0);
		if ((tokens->type == TOK_REDIR_IN || tokens->type == TOK_REDIR_OUT
				|| tokens->type == TOK_APPEND || tokens->type == TOK_HEREDOC)
			&& (!tokens->next || tokens->next->type != TOK_WORD))
			return (write(2, "syntax error: redir without target\n", 36), 0);
		tokens = tokens->next;
	}
	return (1);
}
