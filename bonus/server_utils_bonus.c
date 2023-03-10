/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:49:35 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 14:49:37 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

extern t_control	g_vars;

void	ft_free_exit(void)
{
	ft_ptr_freenull(&g_vars.str);
	exit(EXIT_FAILURE);
}

int	ft_restartsrv(void)
{
	ft_ptr_freenull(&g_vars.str);
	ft_resetvars();
	return (0);
}

int	ft_printpid(void)
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
	if (usleep(5000000) == 0 && g_vars.status == 0)
		return (-1);
	return (0);
}

void	ft_resetvars(void)
{
	g_vars.str = NULL;
	g_vars.len = 0;
	g_vars.i = -1;
	g_vars.status = 2;
	g_vars.initpid = -42;
	g_vars.strpos = 0;
	g_vars.pos_bit = 0;
	g_vars.sig = 0;
	g_vars.sig_processed = 1;
	return ;
}
