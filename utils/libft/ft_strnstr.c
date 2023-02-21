/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:49:26 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/20 10:57:41 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_hay;
	size_t	i;

	i_hay = 0;
	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while ((i_hay + i) < len && haystack[i_hay + i])
	{
		while (haystack[i_hay + i] == needle[i] && haystack[i_hay + i] \
				&& needle[i] && (i_hay + i) < len)
			i++;
		if (needle[i] == 0)
			return ((char *)(haystack + i_hay));
		i_hay++;
		i = 0;
	}
	return (0);
}
