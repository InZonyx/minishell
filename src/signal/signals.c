/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:59:38 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/26 21:32:43 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void    sigint_prompt(int sig)
{
    (void)sig;
}
/*
static void ms_sigaction_set(int signum, void (*fn)(int))
{
    
}*/

void    ms_set_signals_prompt(void)
{
    sigaction_set(SIGINT, sigint_prompt);
    sigaction_set(SIGQUIT, SIG_IGN);
}

void    ms_set_signals_parent_exec(void)
{
    sigaction_set(SIGINT, SIG_IGN);
    sigaction_set(SIGQUIT, SIG_IGN);
}

void    set_signals_child_exec(void)
{
    signaction_set(SIGINT, SIG_DFL);
    signaction_set(SIGQUIT, SIG_DFL);
}