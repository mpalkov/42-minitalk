/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:24:16 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 11:38:14 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

// strlen (man strlen) returns length of a string as size_t data type.
// This type is defined in both of the system headers unistd.h and stdlib.h
// using size_t does not work without these headers or without defining it
// yourself.
//
// MODIFIED 08-08-2022
// checks if input string is NULL. If so, returns 0.
// The sys strlen crashes when the input string is NULL so did the original
// ft_strlen. But using it in the future may give me bad results.
