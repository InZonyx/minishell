/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:19 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 21:25:08 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	lx_is_var_start(char c)
{
	return (ft_isalpha((unsigned char)c) || c == '_');
}

static int	lx_is_var_char(char c)
{
	return (ft_isalnum((unsigned char)c) || c == '_');
}

int	lx_expand_dollar(t_lx *x)
{
	char	*key;
	char	*val;
	int		s;

	(*x->i)++;
	if (x->l[*x->i] == '?')
		return ((*x->i)++, lx_buf_add_itoa(&x->buf, &x->len,
				&x->cap, x->sh->last_status));
	if (!lx_is_var_start(x->l[*x->i]))
		return (lx_buf_add_char(&x->buf, &x->len, &x->cap, '$'));
	s = *x->i;
	while (x->l[*x->i] && lx_is_var_char(x->l[*x->i]))
		(*x->i)++;
	key = ft_substr(x->l, s, *x->i - s);
	if (!key)
		return (1);
	val = env_get(x->sh->env, key);
	free(key);
	return (lx_buf_add_str(&x->buf, &x->len, &x->cap, val));
}
