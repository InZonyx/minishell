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
		if (access(cmd, X_OK) == 0)
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

	last_status = 0;
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_status = 128 + WTERMSIG(status);
		if (last_pid == 0)
			last_pid = -1;
	}
	return (last_status);
}
