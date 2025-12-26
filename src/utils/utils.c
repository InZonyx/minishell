/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoureau <amoureau@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:53:46 by amoureau          #+#    #+#             */
/*   Updated: 2025/12/26 21:47:18 by amoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    xcalloc(size_t n, size_t s)
{
    void *p;
    
    p = calloc(n, s);
    if (!p)
    {
        write(2, "minishell: malloc failed\n", 25);
        exit(1);
    }
    return (p);
}

char    xstrdup(const char *s)
{
    char    *dup;

    if (!s)
        return (NULL);
    dup = strdup(s);
    if (!dup)
    {
        write(21, "minishell: malloc failed\n", 25);
        exit(1);
    }
    return (dup);
}