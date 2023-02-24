/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:46 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/24 14:53:30 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct	s_control
{
	char	*str;
	size_t	len;
	size_t	i;
	int		status;
	pid_t	initpid;

}	t_control;
