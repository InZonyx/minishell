/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:49:06 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:26:26 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>

# include <readline/readline.h>
# include <readline/history.h>

//  Token types 
enum e_token_type
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HEREDOC
};

typedef struct s_token
{
	enum e_token_type	type;
	char				*value;
	struct s_token		*next;
}	t_token;

typedef struct s_redir
{
	enum e_token_type	type;
	char				*target;
	struct s_redir		*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

// Env
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	int		last_status;
	t_env	*env;
	char	**envp;
	t_token	*tokens;
	t_cmd	*cmd;
}	t_shell;

typedef struct s_exec_ctx
{
	t_shell	*sh;
	char	**envp_arr;
}	t_exec_ctx;

typedef struct s_lx
{
	t_shell			*sh;
	const char		*l;
	int				*i;
	char			*buf;
	size_t			len;
	size_t			cap;
}	t_lx;

/* global variable for signals */
extern volatile sig_atomic_t	g_signal_received;

/* lexing */
t_token	*lexer(t_shell *sh, const char *line);
int		is_space(char c);
int		is_operator(char c);
t_token	*new_token(enum e_token_type type, char *value);
void	add_token(t_token **head, t_token *new);
void	free_tokens(t_token *tokens);
t_token	*get_operator(const char *line, int *i);
char	*get_word(t_shell *sh, const char *line, int *i);
int		check_unclosed_quotes(const char *line);
int		lx_buf_init(char **buf, size_t *len, size_t *cap);
int		lx_buf_grow(char **buf, size_t *cap, size_t need);
int		lx_buf_add_char(char **buf, size_t *len, size_t *cap, char c);
int		lx_buf_add_str(char **buf, size_t *len, size_t *cap, const char *s);
int		lx_buf_add_itoa(char **buf, size_t *len, size_t *cap, int n);
int		lx_is_var_start(char c);
int		lx_is_var_char(char c);
int		lx_expand_dollar(t_lx *x);

/* parse */
t_cmd	*parse(t_token *tokens);
t_redir	*new_redir(enum e_token_type type, char *target);
t_cmd	*new_cmd(t_redir *redir, char *value);
void	add_cmd(t_cmd **head, t_cmd *new);
void	free_cmd(t_cmd *cmd);
int		check_syntax_errors(t_token *tokens);
void	add_cmd_redir(t_redir **head, t_redir *new);

/* init / destroy */
int		shell_init(t_shell *sh, char **envp);
void	shell_destroyer(t_shell *sh);

/* prompt loop utils */
int		is_only_spaces(const char *line);
void	handle_eof(t_shell *sh);
void	main_loop(t_shell *sh);
int		process_line(t_shell *sh, const char *line);

/* signals */
void	set_signals_prompt(void);
void	set_signals_parent_exec(void);
void	set_signals_child_exec(void);

/* env functions */
t_env	*env_init(char **envp);
char	*env_get(t_env *env, const char *key);
int		env_set(t_env **env, const char *key, const char *value);
int		env_unset(t_env **env, const char *key);
char	**env_to_array(t_env *env);
void	env_free(t_env *env);

/* builtins */
int		is_builtin(const char *cmd);
int		exec_builtin(t_shell *sh, char **argv);
int		builtin_echo(char **argv);
int		builtin_pwd(void);
int		builtin_env(t_env *env);
int		builtin_exit(t_shell *sh, char **argv);
int		builtin_cd(t_shell *sh, char **argv);
int		builtin_export(t_shell *sh, char **argv);
int		builtin_unset(t_shell *sh, char **argv);

/* exec */
int		apply_redirs(t_redir *redir);
void	exec_child(t_exec_ctx *ctx, t_cmd *cmd, int fd_in, int fd_out);
int		exec_builtin_parent(t_shell *sh, t_cmd *cmd);
char	*resolve_path(t_shell *sh, const char *cmd);
int		wait_all(pid_t last_pid);
int		execute(t_shell *sh);
int		heredoc_read(const char *delimiter);

/* small utils */
void	*xcalloc(size_t n, size_t s);
char	*xstrdup(const char *s);
void	free_strarray(char **arr);

#endif