/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:46 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:02:47 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	save_std(int *in, int *out)
{
	*in = dup(STDIN_FILENO);
	*out = dup(STDOUT_FILENO);
	if (*in < 0 || *out < 0)
		return (perror("minishell: dup"), 0);
	return (1);
}

int	exec_builtin_parent(t_shell *sh, t_cmd *cmd)
{
	int	saved_in;
	int	saved_out;
	int	status;

	if (!save_std(&saved_in, &saved_out))
		return (sh->last_status = 1);
	set_signals_parent_exec();
	if (apply_redirs(cmd->redirs))
		status = 1;
	else
		status = exec_builtin(sh, cmd->argv);
	if (dup2(saved_in, STDIN_FILENO) < 0 || dup2(saved_out, STDOUT_FILENO) < 0)
		perror("minishell: dup2");
	close(saved_in);
	close(saved_out);
	sh->last_status = status;
	return (status);
}
