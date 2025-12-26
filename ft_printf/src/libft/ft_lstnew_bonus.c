/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:34:48 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:30:15 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a new list node. The member variable 'content' is
 * initialized with the value of the parameter 'content'. The variable 'next'
 * is initialized to NULL.
 * Param. #1 The content to create the node with.
 * Return value The newly allocated node, or NULL if the allocation fails.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
