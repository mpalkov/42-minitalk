/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:34:02 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/15 16:43:18 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// man memcpy
// The memcpy() function copies n bytes from memory area src to memory area dst.
// If dst and src overlap, behavior is undefined.
// Applications in which dst and src might overlap
// should use memmove(3) instead.
//
// - if memcpy crashes with certain arguments, ft_memcpy should crash too
// as it should do the same as original memcpy function.
//
// - the following function
// if (d == s)
//		return (d);
//	already does what the below function does, so this one is not necessary
//	if (src == 0 && dst == 0)
//		return (NULL);
//
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// is the same as:
// 
// 		unsigned char	*d;
// 		unsigned char	*s;
// 		d = (unsigned char *)dst;
//	 	s = (unsigned char *)src;
// 		d[i] = s[i];
