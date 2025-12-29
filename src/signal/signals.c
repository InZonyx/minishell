/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:59:38 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 22:50:48 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

volatile sig_atomic_t	g_signal_received = 0;

static void	sigint_prompt(int sig)
{
	(void)sig;
	g_signal_received = SIGINT;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	sigaction_set(int signum, void (*fn)(int))
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = fn;
	sa.sa_flags = 0;
	if (sigaction(signum, &sa, NULL) == -1)
	{
		write(2, "minishell: sigaction failed\n", 28);
		exit(1);
	}
}

void	set_signals_prompt(void)
{
	sigaction_set(SIGINT, sigint_prompt);
	sigaction_set(SIGQUIT, SIG_IGN);
}

void	set_signals_parent_exec(void)
{
	sigaction_set(SIGINT, SIG_IGN);
	sigaction_set(SIGQUIT, SIG_IGN);
}

void	set_signals_child_exec(void)
{
	sigaction_set(SIGINT, SIG_DFL);
	sigaction_set(SIGQUIT, SIG_DFL);
}
