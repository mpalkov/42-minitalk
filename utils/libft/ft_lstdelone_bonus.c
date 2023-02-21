/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:10:36 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/26 19:21:54 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// Takes as a parameter a node and frees the memory of the node’s content
// using the function ’del’ given as a parameter and free the node.
// The memory of ’next’ must not be freed.
//
// Parameters:
// lst: The node to free.
// del: The address of the function used to delete the content.
//
// allowed function: free
