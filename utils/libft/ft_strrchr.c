/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:04:44 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/01 13:16:24 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*lasttemp;

	i = 0;
	str = (char *)s;
	lasttemp = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
			lasttemp = &str[i];
		i++;
		if (str[i] == (char)c)
			lasttemp = &str[i];
	}
	if (str[i] == (char)c)
		lasttemp = &str[i];
	return (lasttemp);
}
