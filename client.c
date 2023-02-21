#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#define USLP usleep(100);
#define STRLEN_BITS (int)64

//intercambiar el orden de recepcion de los argumentos para que el
//pid sea el priero y el string el segundo (intercambiar argv[1] por 2 en main)

static int	fn_checkerr(int argc, char **argv)
{
	(void)**argv;
	int	errn = 0;
	if (argc != 3)
	{
		errn = -1;
		//ft_putstr_fd en lugar de fprintf
		fprintf(stderr, "2 arguments are required in the following order: One number (PID) and one string.\n");
	}
	return (errn);
}

//SIGUSR1 == 30 (so for my server	SIGUSR1 == 0)
//SIGUSR2 == 31 (so for me			SIGUSR2 == 1)
static int	ft_snd_unit_bits(pid_t pid, int unitsize, size_t unit)
{
	char	b = 0;
	int		bit = 0;

	while (bit < unitsize)
	{
		b = (unit >> bit) & 1;
		if (b == 1)
			kill(pid, SIGUSR2);
		else if (b == 0)
			kill(pid, SIGUSR1);
		++bit;
		USLP
	}
	return (0);
}

static int	ft_send(pid_t pid, char *str)
{
	size_t	i = 0;
	//sendlen
	ft_snd_unit_bits(pid, sizeof(size_t) * 8, strlen(str));
	//sendstr
	while (str[i])
		ft_snd_unit_bits(pid, sizeof(str[i]) * 8, str[i++]);
	//send '\0'
	if (str[i] == '\0')
		ft_snd_unit_bits(pid, sizeof(str[i]) * 8, str[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t		srv_pid;
	int	errn = 0;

	if ((errn = fn_checkerr(argc, argv)))
		return (errn);
	srv_pid = ft_atoi(argv[2]);
	ft_send(srv_pid, argv[1]);

//	if ((errn = kill(srv_pid, SIGUSR1)) == -1)
//		return (errn);

	return (0);
}
