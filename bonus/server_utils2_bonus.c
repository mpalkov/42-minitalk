/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:49:24 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 14:49:26 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

extern t_control	g_vars;

int	ft_checkpid(siginfo_t *info)
{
	if (info->si_pid == g_vars.initpid)
		return (0);
	else if (g_vars.i == -1 && g_vars.initpid == -42)
	{
		g_vars.initpid = info->si_pid;
		return (0);
	}
	return (-1);
}

/*		No free in this function on error, because no malloc was created yet.
 *		Exit directly
 *		No write protection, because program exits anyways right after write. */
int	ft_siginit(struct sigaction *s_sa)
{
	s_sa->sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa->sa_sigaction = ft_sigusr;
	s_sa->sa_mask = 0;
	if (sigaction(SIGUSR1, s_sa, NULL) < 0)
	{
		write(STDERR_FILENO, "Error setting up sigaction().\n", 30);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("sigaction 1 OK\n");
	if (sigaction(SIGUSR2, s_sa, NULL) < 0)
	{
		write(STDERR_FILENO, "Error setting up sigaction().\n", 30);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("sigaction 2 OK\n");
	return (0);
}

//	g_vars.i == number of bit received in total (starting at 0)
void	ft_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	(void)ptr;
	if (ft_checkpid(sinfo) == -1)
		return ;
	g_vars.sig = sig;
	g_vars.sig_processed = 0;
	++g_vars.i;
	return ;
}
