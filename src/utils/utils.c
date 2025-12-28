/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:53:46 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 17:03:29 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*xcalloc(size_t n, size_t s)
{
	void	*p;

	p = ft_calloc(n, s);
	if (!p)
	{
		perror("minishell: calloc");
		exit(EXIT_FAILURE);
	}
	return (p);
}

char	*xstrdup(const char *s)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
	{
		perror("minishell: strdup");
		exit(EXIT_FAILURE);
	}
	return (dup);
}

void	free_strarray(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
