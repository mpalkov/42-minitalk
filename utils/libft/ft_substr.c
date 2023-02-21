/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:40:05 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 10:58:19 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s || start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		newstr = malloc(sizeof(char) * 1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (s[start + (unsigned int)i] && i < len)
	{
			newstr[i] = s[start + (unsigned int)i];
			i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/* ft_substr
 * allocates (with malloc(3)) and returns a substring from the
 * string ’s’. The substring begins at index ’start’ and is of
 * maximum size ’len’.
 *
 * if (!s || start >= (unsigned int)ft_strlen(s) || len == 0)
 * works only when created malloc is filled with the 0 byte
 * 		newstr[0] = '\0';
 * if not, memory problems arise, because allocated mem. is empty */
