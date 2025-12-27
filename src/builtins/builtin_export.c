/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:30:00 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:57:11 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		if (env->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}

static int	print_invalid_id(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	return (1);
}

static int	export_var(t_shell *sh, char *arg)
{
	char	*equal;
	char	*key;
	char	*value;

	if (!is_valid_identifier(arg))
		return (print_invalid_id(arg));
	equal = ft_strchr(arg, '=');
	if (!equal)
		return (0);
	key = ft_substr(arg, 0, equal - arg);
	value = ft_strdup(equal + 1);
	if (!key || !value)
	{
		free(key);
		free(value);
		return (1);
	}
	env_set(&sh->env, key, value);
	free(key);
	free(value);
	return (0);
}

int	builtin_export(t_shell *sh, char **argv)
{
	int	i;
	int	ret;

	if (!argv[1])
	{
		print_export(sh->env);
		return (0);
	}
	ret = 0;
	i = 1;
	while (argv[i])
	{
		if (export_var(sh, argv[i]) != 0)
			ret = 1;
		i++;
	}
	return (ret);
}
