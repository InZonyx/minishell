/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:09:30 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:10:44 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	parse_env_line(const char *line, char **key, char **value)
{
	char	*eq;

	eq = ft_strchr(line, '=');
	if (!eq)
		return (0);
	*key = ft_substr(line, 0, eq - line);
	*value = ft_strdup(eq + 1);
	if (!*key || !*value)
	{
		free(*key);
		free(*value);
		return (0);
	}
	return (1);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	char	*key;
	char	*value;
	int		i;

	env = NULL;
	i = 0;
	while (envp && envp[i])
	{
		if (parse_env_line(envp[i], &key, &value))
		{
			env_set(&env, key, value);
			free(key);
			free(value);
		}
		i++;
	}
	return (env);
}

void	env_free(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

static int	env_size(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

char	**env_to_array(t_env *env)
{
	char	**arr;
	char	*tmp;
	int		i;

	arr = malloc(sizeof(char *) * (env_size(env) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env)
	{
		tmp = ft_strjoin(env->key, "=");
		arr[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		if (!arr[i])
			return (NULL);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
