/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:17:43 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/26 22:02:02 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	len_token(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && !is_space_char(line[i]))
		i++;
	return (i + 1);
}

int	token_amount(const char *line)
{
	int	i;
	int	x;

	if (!line)
		return (1);
	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] && is_space_char(line[i]))
			i++;
		if (!line[i])
			break ;
		while (line[i] && !is_space_char(line[i]))
			i++;
		x++;
	}
	return (x + 1);
}

void	tokenise(t_shell *sh, const char *line)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	sh->token = malloc(sizeof(char *) * token_amount(line));
	if (!sh->token)
		return ;
	while (line[i])
	{
		while (line[i] && is_space_char(line[i]))
			i++;
		if (!line[i])
			break ;
		j = 0;
		sh->token[x] = malloc(sizeof(char) * len_token(&line[i]));
		if (!sh->token[x])
			return ;
		while (line[i] && !is_space_char(line[i]))
			sh->token[x][j++] = line[i++];
		sh->token[x][j] = '\0';
		x++;
	}
	sh->token[x] = NULL;
}
