/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:21:31 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 14:42:23 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	fn_checkerr(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc != 3)
	{
		write(STDERR_FILENO, "ERROR! 2 arguments are required in the following"
			" order: One number (PID) and one string.\n", 89);
		return (-1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			write(STDERR_FILENO, "ERROR! PID should be a positive"
				" number.\n", 40);
			return (-1);
		}
	}
	return (0);
}

/*		SIGUSR1 == 30 (so for my server	SIGUSR1 == 0)
 *		SIGUSR2 == 31 (so for my server SIGUSR2 == 1) */
static int	ft_snd_unit_bits(pid_t pid, int unitsize, size_t unit)
{
	char	b;
	int		bit;

	b = 0;
	bit = 0;
	while (bit < unitsize)
	{
		b = (unit >> bit) & 1;
		if (kill(pid, SIGUSR1 + b) == -1)
		{
			write(STDERR_FILENO, "Error sending signals! Wrong PID?\n", 34);
			exit(EXIT_FAILURE);
		}
		++bit;
		usleep(USLP);
	}
	return (0);
}

/*		First a (size_t)length is decomposed to bits and sent.
 *		(After receiving this number, server creates calloc of that size.)
 *		Then the actual string is send as bits char-by-char. */
static int	ft_send(pid_t pid, char *str)
{
	size_t	i;

	i = 0;
	ft_snd_unit_bits(pid, sizeof(size_t) * 8, ft_strlen(str));
	while (str[i])
		ft_snd_unit_bits(pid, sizeof(str[i]) * 8, str[i++]);
	if (str[i] == '\0')
		ft_snd_unit_bits(pid, sizeof(str[i]) * 8, str[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	srv_pid;

	if (fn_checkerr(argc, argv) == -1)
		exit(EXIT_FAILURE);
	srv_pid = ft_atoi(argv[1]);
	ft_send(srv_pid, argv[2]);
	return (0);
}
