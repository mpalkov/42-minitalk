/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:00:01 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/01 15:13:01 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d_size;
	unsigned int	s_size;
	unsigned int	i;

	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (s_size);
	if (dstsize <= d_size)
		return (dstsize + s_size);
	while (dstsize && (--dstsize - d_size) && src[i])
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = 0;
	return (d_size + s_size);
}

// strlcat() take the full size of the destination buffer and guarantee NUL-
// termination if there is room.
// Note that room for the NUL should be included in dstsize.
//
// strlcat() appends string src to the end of dst.  It will append
// at most dstsize - strlen(dst) - 1 characters.
// It will then NUL-terminate, unless dstsize is 0 or the original dst string
// was longer than dstsize (in practice this should not happen as it means
// that either dstsize is incorrect or that dst is not a proper string).
//
// If the src and dst strings overlap, the behavior is undefined.
//
//RETURN
// the strlcpy() and strlcat() functions return the total length of the
// string they tried to create. 
// For strlcat() that means the initial length of dst plus the length of src.
