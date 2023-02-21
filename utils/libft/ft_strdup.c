/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:14:58 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 11:34:44 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*newstr;

	len = ft_strlen(str);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	len = 0;
	while (str[len])
	{
		newstr[len] = str[len];
		++len;
	}
	newstr[len] = '\0';
	return (newstr);
}

/* MAN STRDUP
 * The strdup() function allocates sufficient memory for a copy of the string s1,
 * does the copy, and returns a pointer to it.  The pointer may subsequently
 * be used as an argument to the function free(3).

 * If insufficient memory is available, NULL is returned.

 * The strndup() function copies at most n characters from the string s1
 * always NUL terminating the copied string. */

/* First length of original string is determined, then memory
 * is allocated by malloc with size + 1 because string count starts at 0,
 * but malloc starts counting at 1. */
