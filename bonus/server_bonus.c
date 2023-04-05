/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:49:10 by mpalkov           #+#    #+#             */
/*   Updated: 2023/04/05 14:55:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_control	g_vars;

int	ft_bits2str(int sig)
{
	g_vars.strpos = (g_vars.i - sizeof(g_vars.len) * 8) / \
				(sizeof(char) * 8);
	g_vars.pos_bit = (g_vars.i - sizeof(g_vars.len) * 8) % \
			(sizeof(char) * 8);
	g_vars.str[g_vars.strpos] = (g_vars.str[g_vars.strpos]) | \
			(sig << g_vars.pos_bit);
	if (g_vars.pos_bit == 7 && g_vars.str[g_vars.strpos] == '\0')
	{
		if (g_vars.strpos == g_vars.len)
		{
			g_vars.sig_processed = 1;
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
	return (0);
}

/*		This function handles the received bits.
 *		First it, creates number from bits-set of sizeof(ssize_t).
 *		Second, after completing the former number, allocates mem.
 *			of this size with calloc. Like this, everything is 0 and i can
 *			start bit-operating on it directly.
 *		Third, ft_bits2str handles rest of the received bits adding them
 *		to corresponmding str[currentposition]. */
static int	ft_rcvbits(int sig)
{
	if (g_vars.i < (ssize_t)(sizeof(g_vars.len) * 8))
		g_vars.len = sig << g_vars.i | g_vars.len;
	if (g_vars.i == (ssize_t)(sizeof(g_vars.len) * 8 - 1))
	{
		g_vars.str = calloc(g_vars.len + 1, sizeof(char));
		if (!g_vars.str)
		{
			write(STDERR_FILENO, "Error! Malloc problems.\n", 24);
			exit(EXIT_FAILURE);
		}
	}
	else if (g_vars.i >= (ssize_t)(sizeof(g_vars.len) * 8))
	{
		if (ft_bits2str(sig) == 1)
			return (1);
	}
	g_vars.sig_processed = 1;
	return (0);
}

static int	ft_loop(void)
{
	if (!g_vars.sig_processed)
	{
	g_vars.status = ft_rcvbits(g_vars.sig - SIGUSR1);
		if (g_vars.status == 1)
		{
			if (ft_printf("\n\nReceived string length is: %d bytes\n"
					"String: %s\n\nAwaiting new message.\n", \
					g_vars.len, g_vars.str) == -1)
				ft_free_exit();
			ft_restartsrv();
		}
	}
	return (0);
}

int	main(void)
{
	struct sigaction	s_sa;

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
