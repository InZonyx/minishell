/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:09:28 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:18:15 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_shell *sh, char **argv)
{
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (builtin_echo(argv));
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (builtin_cd(sh, argv));
	if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (builtin_pwd());
	if (ft_strncmp(argv[0], "export", 7) == 0)
		return (builtin_export(sh, argv));
	if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (builtin_unset(sh, argv));
	if (ft_strncmp(argv[0], "env", 4) == 0)
		return (builtin_env(sh->env));
	if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (builtin_exit(sh, argv));
	return (1);
}
