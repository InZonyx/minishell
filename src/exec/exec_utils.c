/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:25 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 23:29:25 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*build_cmd_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	*find_in_paths(char **paths, const char *cmd)
{
	char	*full;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		full = build_cmd_path(paths[i], cmd);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

char	*resolve_path(t_shell *sh, const char *cmd)
{
	char	**paths;
	char	*full;
	char	*path_var;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (xstrdup(cmd));
		return (NULL);
	}
	path_var = env_get(sh->env, "PATH");
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	full = find_in_paths(paths, cmd);
	free_strarray(paths);
	return (full);
}

int	wait_all(pid_t last_pid)
{
	int	status;
	int	last_status;
	pid_t	pid;

	last_status = 0;
	while ((pid = wait(&status)) > 0)
	{
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_status = 128 + WTERMSIG(status);
		}
	}
	return (last_status);
}
