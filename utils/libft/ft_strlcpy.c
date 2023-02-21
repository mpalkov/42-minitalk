/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:51:11 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/01 15:07:49 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

// strlcpy() and strlcat() take the full size of the destination buffer
// and guarantee NUL-termination if there is room.
// Note that room for the NUL should be included in dstsize.

// strlcpy() copies up to dstsize - 1 characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0.
//
// RETURN
// the strlcpy() and strlcat() functions return the total length of the
// string they tried to create. For strlcpy() that means the length of src.
