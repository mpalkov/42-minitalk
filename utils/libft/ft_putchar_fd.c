/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:28:05 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/23 16:29:30 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (sizeof(char));
}

// As input variable c is of type char which is 1 byte,
// the length of bytes to write will be always 1, so I don't use sizeof(char).
