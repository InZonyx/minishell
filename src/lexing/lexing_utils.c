/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:17:00 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:50:07 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	add_token(t_token **head, t_token *new)
{
	t_token	*tmp;

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

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}
