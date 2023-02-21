/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:59:36 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/01 14:59:54 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = (int)len - 1;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (i > -1)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// The memmove() function copies len bytes from string src to string dst.
//  The two strings may overlap;
//  the copy is always done in a non-destructive manner.
//
//  The memmove() function returns the original value of dst.

// the following function
// if (d == s)
//		return (d);
//	already does what the below function does, so this one is not necessary
//	if (src == 0 && dst == 0)
//		return (NULL);
