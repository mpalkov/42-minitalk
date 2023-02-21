/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:23:35 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/27 13:18:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// Deletes and frees the given node and every successor of that node,
// using the function ’del’ and free(3).
// Finally, the pointer to the list must be set to NULL.
//
// Parameters:
// lst: The address of a pointer to a node.
// del: The address of the function used to delete the content of the node.

// No need to set *lst = 0 after the while loop finishes,
// because in the last node, the temp = (*lst)->next; the next is NULL,
// so in 2 lines *lst = temp makes *lst = NULL or 0;

// the lines del and free can be replaced by my ft_lstdelone which is the same.
