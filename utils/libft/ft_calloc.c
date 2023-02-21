/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:49:27 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/28 15:14:46 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmbyte, size_t size)
{
	void	*ptr;

	ptr = 0;
	ptr = malloc(nmbyte * size);
	if (ptr == 0)
		return (0);
	return (ft_memset(ptr, 0, nmbyte * size));
}
