/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:20:43 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/25 14:23:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*mylist;

	mylist = (t_list *)malloc(sizeof(*mylist));
	if (!mylist)
		return (0);
	mylist->content = content;
	mylist->next = NULL;
	return (mylist);
}

//  Allocates (with malloc(3)) and returns a new node.
//  The member variable ’content’ is initialized with
//  the value of the parameter ’content’. The variable
//  ’next’ is initialized to NULL.
//
//  Return value: The new node
