/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:04:40 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:03 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Takes as a parameter a node and frees the memory of the node’s content using
 * the function 'del' given as a parameter and free the node. The memory of
 * 'next' must not be freed.
 * Param. #1 The node to free.
 * Param. #2 The address of the function used to delete the content of the node.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
