/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:56:17 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/24 17:52:12 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (write(fd, &s[i], sizeof(char)) != sizeof(char))
			return (-1);
		i++;
	}
	if (write(fd, "\n", sizeof(char)) != sizeof(char))
		return (-1);
	return (sizeof(char) * i);
}

// Outputs the string ’s’ to the given file descriptor followed by a newline.
