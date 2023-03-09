/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/09 16:52:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_control	vars;

static int ft_rcvbits(int sig)
{
	if (vars.i < (ssize_t)(sizeof(vars.len) * 8))
		vars.len = sig << vars.i | vars.len;
	if (vars.i == (ssize_t)(sizeof(vars.len) * 8 - 1))
	{
		if (!(vars.str = calloc(vars.len + 1, sizeof(char))))
		{
			write(STDERR_FILENO, "Error! Malloc problems.\n", 24);
			exit(EXIT_FAILURE);
		}
	}
	else if (vars.i >= (ssize_t)(sizeof(vars.len) * 8))
	{
		vars.strpos = (vars.i - sizeof(vars.len) * 8) / (sizeof(char) * 8);
		vars.pos_bit = (vars.i - sizeof(vars.len) * 8) % (sizeof(char) * 8);
		vars.str[vars.strpos] = (vars.str[vars.strpos]) | (sig << vars.pos_bit);
		if (vars.pos_bit == 7 && vars.str[vars.strpos] == '\0')
		{
			if (vars.strpos == vars.len)
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

//	i == number of bit received in total (starting at 0)
static void	ft_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	(void)ptr;

	if (ft_checkpid(sinfo) == -1)
		return ;
	vars.sig = sig;
	vars.sig_processed = 0;
	++vars.i;
	return ;
}

/*		No free in this function on error, because no malloc was created yet.
 *		Exit directly
 *		No write protection, because program exits anyways right after write. */
static int	ft_siginit(struct sigaction *s_sa)
{
	s_sa->sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa->sa_sigaction = ft_sigusr;
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

static int	ft_loop(void)
{
	if (!vars.sig_processed)
	{
		if ((vars.status = ft_rcvbits(vars.sig - SIGUSR1)) == 1)
		{
			if (ft_printf("\n\nReceived string length is: %d bytes\n"
						"String: %s\n\nAwaiting new transmission\n", \
						vars.len, vars.str) == -1)
				ft_free_exit();
			ft_restartsrv();
		}
	}
	return (0);
}

int	main(void)
{
	struct sigaction	s_sa = {0};
	
	ft_resetvars();
	ft_siginit(&s_sa);
	ft_printpid();
	while (42)
	{
		if (ft_timeoutcheck() == -1)
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
