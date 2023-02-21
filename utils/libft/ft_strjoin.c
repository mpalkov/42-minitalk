/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:51:08 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 11:29:30 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*newstr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j <= len2)
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	return (newstr);
}

/* Allocates (with malloc(3)) and returns a new string, which is the result
 * of the concatenation of ’s1’ and ’s2’.

Only important thing is to omit the terminating '\0' in the first string */
