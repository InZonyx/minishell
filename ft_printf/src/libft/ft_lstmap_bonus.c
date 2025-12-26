/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:25:31 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:11 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates the list 'lst' and applies the function 'f' to the content of each
 * node. Creates a new list resulting of the successive applications of 'f'.
 * The 'del' function is used to delete the content of a node if needed.
 * Param. #1 The address of a pointer to a node.
 * Param. #2 The address of the function used to iterate on the list.
 * Param. #3 The address of the function used to delete the content of a node
 * if needed.
 * Return value The new list, or NULL if the allocation fails.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*new_content;

	head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (!node)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
