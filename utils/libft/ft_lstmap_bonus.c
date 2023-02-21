/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:08:32 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/29 17:46:11 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	t_list	*tempnode;

	newlist = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		tempnode = f(lst->content);
		newnode = ft_lstnew(tempnode);
		if (!newnode)
		{
			del(tempnode);
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

//Iterates the list ’lst’ and applies the function ’f’ on the
//content of each node. Creates a new list resulting of the successive
//applications of the function ’f’. The ’del’ function is used to
//delete the content of a node if needed.
//
//Parameters:
//lst: The address of a pointer to a node.
//f: The address of the function used to iterate on the list.
//del: The address of the function used to delete the content of a node
//if needed.
