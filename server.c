/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/06 17:14:40 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_control	vars;


void	ft_free_exit(void)
{
	ft_ptr_freenull(&vars.str);
	exit(EXIT_FAILURE);
}

static void	ft_resetvars(void)
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

static int	ft_restartsrv(void)
{
	ft_ptr_freenull(&vars.str);
	ft_resetvars();
	return (0);
}

static int ft_rcvbits(int sig)
{
	if (vars.i < (sizeof(vars.len) * 8))
		vars.len = sig << vars.i | vars.len;
	if (vars.i == (sizeof(vars.len) * 8 - 1))
	{
		if (!(vars.str = calloc(vars.len + 1, sizeof(char))))
		{
			write(STDERR_FILENO, "Error! Malloc problems.\n", 24);
			exit(EXIT_FAILURE);
		}
	}
	else if (vars.i >= sizeof(vars.len) * 8)
	{
		vars.strpos = (vars.i - sizeof(vars.len) * 8) / (sizeof(char) * 8);
		vars.pos_bit = (vars.i - sizeof(vars.len) * 8) % (sizeof(char) * 8);
		vars.str[vars.strpos] = (vars.str[vars.strpos]) | (sig << vars.pos_bit);
		if (vars.pos_bit == 7 && vars.str[vars.strpos] == '\0')
		{
			if (vars.strpos == vars.len - 1)
			{
				vars.sig_processed = 1;
				return (1);
			}
			else
			{
				ft_restartsrv();
				if (write(STDERR_FILENO, "Error! Received bits mismatch.\n"
						"Server restarted.\n", 49) == -1)
					exit(EXIT_FAILURE);
			}
		}
	}
	vars.sig_processed = 1;
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

//	i == number of bit received in total (starting at 0)
static void	fn_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	(void)ptr;

	if (ft_checkpid(sinfo, vars.i) == -1)
		return ;

	vars.sig = sig;
	vars.sig_processed = 0;
	++vars.i;
	return ;
}

static void	ft_sigint(int sig, siginfo_t *sinfo, void *ptr)
{
	ft_ptr_freenull(&vars.str);
	ft_printf("\nSuccessfully liberated used memory."
			"\nProgramm closed successfully.\n");
	exit(EXIT_SUCCESS);
}

//		No free in this function on error, because no malloc was created yet.
//		Exit directly
//		No write protection, because program exits anyways right after write.
static int	ft_siginit(struct sigaction *s_sa, struct sigaction *s_sigint)
{
	s_sa->sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa->sa_sigaction = fn_sigusr;
	s_sigint->sa_flags = SA_RESTART | SA_SIGINFO;
	s_sigint->sa_sigaction = ft_sigint;
	if (sigaction(SIGUSR1, s_sa, NULL) < 0)
	{
		write(STDERR_FILENO, "Error setting up sigaction().\n", 30);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, s_sa, NULL) < 0)
	{
		write(STDERR_FILENO, "Error setting up sigaction().\n", 30);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGINT, s_sigint, NULL) < 0)
	{
		write(STDERR_FILENO, "Error setting up sigaction().\n", 30);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	ft_printpid()
{
	if (ft_printf("PID: %d\n", getpid()) == -1)
	{
		write(STDERR_FILENO, "Error getting PID.\n", 19);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	ft_loop(void)
{	
	if (!vars.sig_processed)
	{
		if ((vars.status = ft_rcvbits(vars.sig - SIGUSR1)) == 1)
		{
			if (ft_printf("\n\nReceived string length is: %d bytes\n"
						"String: %s\n\nAwaiting new transmission", \
						vars.len, vars.str) == -1)
				ft_free_exit();
			ft_restartsrv();
		}
	}
	return (0);
}

static int	ft_timeoutcheck(int s)
{
	while (s-- > 0)
	{
		if (usleep(999999) == 0 && vars.status == 0)
			return (-1);
	}
	return (0);
}

int	main(void)
{
	struct sigaction	s_sa = {0};
	struct sigaction	s_sigint = {0};
	
	ft_resetvars();
	ft_siginit(&s_sa, &s_sigint);
	ft_printpid();
	while (1)
	{
		if (ft_timeoutcheck(5) == -1)
		{
			ft_restartsrv();
			if (ft_printf("Timeout! No signal received in the last 5 seconds.\n"
					"Awaiting new message.\n") == -1)
				ft_free_exit();
		}
		ft_loop();
	}
	return (0);
}
