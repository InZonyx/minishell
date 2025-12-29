/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:09:11 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:06:12 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	update_pwd(t_shell *sh, const char *oldpwd)
{
	char	cwd[4096];

	if (oldpwd && oldpwd[0])
		env_set(&sh->env, "OLDPWD", oldpwd);
	if (getcwd(cwd, sizeof(cwd)))
		env_set(&sh->env, "PWD", cwd);
}

static char	*expand_tilde(t_shell *sh, char *arg)
{
	char	*home;

	if (!arg || arg[0] != '~')
		return (NULL);
	home = env_get(sh->env, "HOME");
	if (!home)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (NULL);
	}
	if (arg[1] == '\0')
		return (ft_strdup(home));
	if (arg[1] == '/')
		return (ft_strjoin(home, arg + 1));
	return (NULL);
}

static char	*get_cd_path(t_shell *sh, char **argv, int *must_free)
{
	char	*path;

	*must_free = 0;
	if (!argv[1])
	{
		path = env_get(sh->env, "HOME");
		if (!path)
			ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (path);
	}
	if (argv[1][0] == '~')
	{
		*must_free = 1;
		return (expand_tilde(sh, argv[1]));
	}
	if (ft_strncmp(argv[1], "-", 2) == 0)
	{
		path = env_get(sh->env, "OLDPWD");
		if (!path)
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		else
			ft_putendl_fd(path, 1);
		return (path);
	}
	return (argv[1]);
}

static int	do_chdir(char *path, int must_free)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		if (must_free)
			free(path);
		return (1);
	}
	if (must_free)
		free(path);
	return (0);
}

int	builtin_cd(t_shell *sh, char **argv)
{
	char	*path;
	char	oldpath[4096];
	int		must_free;

	if (argv[1] && argv[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		return (1);
	}
	if (!getcwd(oldpath, sizeof(oldpath)))
		oldpath[0] = '\0';
	path = get_cd_path(sh, argv, &must_free);
	if (!path)
		return (1);
	if (do_chdir(path, must_free))
		return (1);
	update_pwd(sh, oldpath);
	return (0);
}
