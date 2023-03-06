/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:46 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/06 17:02:09 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

#include <stdio.h>
typedef struct	s_control
{
	char	*str;
	size_t	len;
	ssize_t	i;
	int		status;
	pid_t	initpid;
	size_t	strpos;
	int		pos_bit;
	int		sig;
	int		sig_processed;

}	t_control;
