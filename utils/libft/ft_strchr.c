/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:34:55 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 11:07:21 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c && str[i] != '\0')
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	else
		return (NULL);
}

// The strchr() function locates the first occurrence of c (converted to a char)
// in the string pointed to by s. The terminating null character is considered
// to be part of the string; therefore if c is `\0', the functions locate the
// terminating `\0'.

//  The strrchr() function is identical to strchr(), except it locates the last
//  occurrence of c.

// RETURN VALUES
// The functions strchr() and strrchr() return a pointer to the located charac-
// ter, or NULL if the character does not appear in the string.
//
// This function does the same SEGFAULT as system strchr() if s == NULL.
// The error handling should be outside of this function
// as this one does only it's job.
