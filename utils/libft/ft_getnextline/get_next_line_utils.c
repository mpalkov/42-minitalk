/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:12:18 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 15:27:22 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_strjoin_free_s1(char *s1, char *s2)
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
	newstr = (char *)malloc(len1 + len2 + 1);
	if (!newstr)
		return (ft_char_freenull(&s1));
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	ft_char_freenull(&s1);
	return (newstr);
}

char	*ft_strchr_nosegf(char *s, int c)
{
	if (!s)
		return (NULL);
	else
		return (ft_strchr(s, c));
}
