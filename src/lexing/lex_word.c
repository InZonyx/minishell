/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:02:58 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/28 23:54:10 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	lx_init_ctx(t_lx *x, t_shell *sh, const char *l, int *i)
{
	x->sh = sh;
	x->l = l;
	x->i = i;
	if (lx_buf_init(&x->buf, &x->len, &x->cap))
		return (1);
	return (0);
}

static int	lx_read_quoted(t_lx *x, char q)
{
	(*x->i)++;
	while (x->l[*x->i] && x->l[*x->i] != q)
	{
		if (q == '"' && x->l[*x->i] == '$')
		{
			if (lx_expand_dollar(x))
				return (1);
			continue ;
		}
		if (lx_buf_add_char(&x->buf, &x->len, &x->cap, x->l[(*x->i)++]))
			return (1);
	}
	if (x->l[*x->i] == q)
		(*x->i)++;
	return (0);
}

static int	lx_read_plain(t_lx *x)
{
	if (x->l[*x->i] == '$')
		return (lx_expand_dollar(x));
	return (lx_buf_add_char(&x->buf, &x->len, &x->cap,
			x->l[(*x->i)++]));
}

char	*get_word(t_shell *sh, const char *l, int *i)
{
	t_lx	x;

	if (lx_init_ctx(&x, sh, l, i))
		return (NULL);
	while (l[*i] && !is_space(l[*i]) && !is_operator(l[*i]))
	{
		if (l[*i] == '\'' || l[*i] == '"')
		{
			if (lx_read_quoted(&x, l[*i]))
				return (free(x.buf), NULL);
		}
		else if (lx_read_plain(&x))
			return (free(x.buf), NULL);
	}
	if (x.len == 0)
		x.buf[0] = '\0';
	return (x.buf);
}
