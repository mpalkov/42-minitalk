/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/24 14:53:22 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_control	vars;

static int ft_rcvbits(int sig)
{
	if (vars.i < (sizeof(vars.len) * 8))
	{
		vars.len = sig << vars.i | vars.len;
	}
	if (vars.i == (sizeof(vars.len) * 8 - 1))
	{
		if (!(vars.str = calloc(vars.len + 1, sizeof(char))))
		{
			write(STDERR_FILENO, "Error! Malloc problems.\n", 24);
			exit (-1);
		}
	}
	else if (vars.i >= sizeof(vars.len) * 8)
	{
		vars.strpos = (vars.i - sizeof(vars.len) * 8) / (sizeof(char) * 8);
		vars.pos_bit = (vars.i - sizeof(vars.len) * 8) % (sizeof(char) * 8);
		vars.str[vars.strpos] = (vars.str[vars.strpos]) | (sig << vars.pos_bit);
		if (vars.pos_bit == 7 && vars.str[vars.strpos] == '\0')
			return (1);
	}
	return (0);
}

static int	ft_checkpid(siginfo_t *info, size_t i)
{
	if (info->si_pid == vars.initpid)
		return (0);
	else if (vars.i == 0 && vars.initpid == -42)
	{
		vars.initpid = info->si_pid;
		return (0);
	}
	return (-1);
}

static void	ft_resetvars(void)
{
	vars.str = NULL;
	vars.len = 0;
	vars.i = 0;
	vars.status = 2;
	vars.initpid = -42;
	vars.strpos = 0;
	vars.pos_bit = 0;
	return ;
}

static int	ft_restartsrv(void)
{
	ft_ptr_freenull(&vars.str);
	ft_resetvars();
	return (0);
}

//	i == number of bit received in total (starting at 0)
static void	fn_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	(void)ptr;

	if (ft_checkpid(sinfo, vars.i) == -1)
			return ;
	if ((vars.status = ft_rcvbits(sig - SIGUSR1)) == 1)
	{
		if (ft_printf("\n\nReceived string length is: %d bytes\n"
					"String: %s\n\n", vars.len, vars.str) == -1)
		{
			ft_ptr_freenull(&vars.str);
			exit(-1);
		}
		ft_restartsrv();
	}
	else 
		++vars.i;
	return;
}

int	main(void)
{
	struct sigaction	s_sa = {0};

	ft_resetvars();
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sa_sigaction = fn_sigusr;
	if (sigaction(SIGUSR1, &s_sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &s_sa, NULL) == -1)
		return (-1);
	if (ft_printf("PID: %d\n", getpid()) == -1)
		return (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
