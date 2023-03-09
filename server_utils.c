/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:02:29 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/09 15:17:47 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_free_exit(void)
{
	ft_ptr_freenull(&vars.str);
	exit(EXIT_FAILURE);
}

int	ft_restartsrv(void)
{
	ft_ptr_freenull(&vars.str);
	ft_resetvars();
	return (0);
}

int	ft_printpid()
{
	if (ft_printf("PID: %d\n", getpid()) == -1)
	{
		write(STDERR_FILENO, "Error getting PID.\n", 19);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_timeoutcheck(void)
{
	if (usleep(5000000) == 0 && vars.status == 0)
		return (-1);
	return (0);
}

void	ft_resetvars(void)
{
	vars.str = NULL;
	vars.len = 0;
	vars.i = -1;
	vars.status = 2;
	vars.initpid = -42;
	vars.strpos = 0;
	vars.pos_bit = 0;
	vars.sig = 0;
	vars.sig_processed = 1;
	return ;
}

