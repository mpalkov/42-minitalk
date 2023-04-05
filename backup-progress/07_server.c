/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/24 13:09:09 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write, sleep, usleep
#include <signal.h> //signals
#include <stdio.h>
#include <stdlib.h> //malloc, free, exit
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

calloc

static int ft_inspectstr(int sig, size_t *i, size_t *len, int unitsize, char **str)
{
	(void)sig;
	return (0);
}

	//sig argument is (sig - SIGUSR1) so it will be directly (int)1 or 0;
	//strpos - position in the char * array.
	//pos_bit - bit number in the strpos position.
	//first unitsize will be size_t (64 bits), so 0 to 64 it will be this if()
	// if counter arrived to complete the first bites-set which makes the len, create malloc of len length.
	//afterwards the else if will construct each str char with its bits untill final '\0' is detected after its' creation
	//
		// strpos counts in which position of our string are we currently working
		//
		// pos_bit indicates, which is the currently received bit of our current byte (strpos)
		//
		//add the current bit to the current byte.
		(*str)[strpos] = ((*str)[strpos]) | ((sig) << pos_bit);
		//if received last bit of char, check if it was a '\0' which indicates end of the operation.
static int ft_rcvbits(int sig, size_t *i, size_t *len, char **str)
{
	static int	strpos;
	static int	pos_bit;

	strpos = 0;
	pos_bit = 0;
	if (*i < (sizeof(*len) * 8))
	{
		*len = sig << *i | *len;
	}
	if (*i == (sizeof(*len) * 8 - 1))
	{
		if (!(*str = calloc(*len + 1, sizeof(char))))
		{
			write(stderr, "Error. Malloc problems.\n", 24);
			exit (-1);
		}
	}
	else if (*i >= sizeof(*len) * 8)
	{
		strpos = (*i - sizeof(*len) * 8) / (sizeof(char) * 8);
		pos_bit = (*i - sizeof(*len) * 8) % (sizeof(char) * 8);
		(*str)[strpos] = ((*str)[strpos]) | ((sig) << pos_bit);
		if (pos_bit == 7 && (*str)[strpos] == '\0')
			return (1);
	}
	return (0);
}

static int	ft_checkpid(siginfo_t *info, size_t i)
{
	//modificar esta funcion. Crear una estructura en main y pasarla a toda fn.
	if (info->si_pid == initpid)
		return (0);
	else if (i == 0 && initpid == -42);
	{
		initpid = info->si_pid;
		return (0);
	}
	return (-1);
}

static int	ft_restartsrv(char **str, size_t *len, size_t *i, int *status)
{
	ft_ptr_freenull(&str);
	len = 0;
	i = 0;
	status = 2;

	return (0);
}

static int	ft_timeoutcheck(int s, int status)
{
	while (s-- > 0)
	{
		if (usleep(1000000) == 0 && status != 2)
			return (0);
	}
	return (-1);
}

//	i == number of bit received in total (starting at 0)
static void	fn_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	static char		*str = NULL;
	static size_t	len = 0;
	static size_t	i = 0;
	static int		status = 2;
	static pid_t	initpid = -42;
	(void)ptr;
	(void)sinfo;

	if (ft_checkpid == -1)
	{
		ft_ptr_freenull(&str);
		write(stderr, "Error. Received signals from multiple PIDs simultaneously.\n",
			   	59);
		sleep(5)
		return (-1);
	}
	if ((status = ft_rcvbits(sig - SIGUSR1, &i, &len, &str)) == 1)
	{
		ft_printf("\n\n***************\nReceived string length is: %d bytes\nString: %s\nEND.\n************\n", len, str);
		ft_restartsrv(&str, &len, &i, &status);
		}
	else 
		++i;
	if (ft_timeoutcheck(5))
	{
		ft_restartsrv(&str, &len, &i, &status);
		write(stderr, "Timeout. No signal received in the last 5 seconds."
				" Awaiting new message.\n", 73);
	}
	return;
}

int	main(void)
{
	struct sigaction	s_sa = {0};
	
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sa_sigaction = fn_sigusr;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL); 
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
