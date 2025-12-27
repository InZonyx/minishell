/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:59:38 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/27 16:44:50 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void    sigint_prompt(int sig)
{
    (void)sig;
    g_last_status = 130;
    write(1, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

static void sigaction_set(int signum, void (*fn)(int))
{
    struct sigaction    sa;
    
    memset(&sa, 0, sizeof(sa));
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = fn;
    sa.sa_flags = SA_RESTART;
    if (sigaction(signum, &sa, NULL) == -1)
    {
        write(2, "minishell: sigaction failed\n", 28);
        exit(1);
    }
}

void    set_signals_prompt(void)
{
    sigaction_set(SIGINT, sigint_prompt);
    sigaction_set(SIGQUIT, SIG_IGN);
}

void    set_signals_parent_exec(void)
{
    sigaction_set(SIGINT, SIG_IGN);
    sigaction_set(SIGQUIT, SIG_IGN);
}

void    set_signals_child_exec(void)
{
    signaction_set(SIGINT, SIG_DFL);
    signaction_set(SIGQUIT, SIG_DFL);
}
