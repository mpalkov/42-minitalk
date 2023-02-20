#include <unistd.h> //write
#include <signal.h> //signals
#include <stdio.h>
#include <stdlib.h> //malloc, free

typedef struct	s_vars
{
	char	*str;
}	t_vars;

static int ft_inspectstr(int sig, size_t *i, size_t *len, int unitsize, char **str)
{
	(void)sig;
	return (0);
}

static int ft_bits2len(int sig, size_t *i, size_t *len, int unitsize, char **str)
{
	static int	bit = 0;
	//first unitsize will be size_t (64 bits), so 0 to 64 it will be this if
	printf("*i == %zu\n", *i);
	if (*i < (sizeof(*len) * 8))
	{
		*len = (sig - SIGUSR1) << *i | *len;
		printf("len = %zu\n", *len);
	}
	if (*i == (sizeof(*len) * 8 - 1))
	{
		printf("\nmalloc len = %zu\n", *len);
		if (!(*str = calloc(*len + 1, sizeof(char))))
			return (-1);
		printf("*str = %p, **str = %p, calloc = %zu\n", *str, str, (*len + 1) * sizeof(char));
	}
	else if (*i >= sizeof(*len) * 8)
	{
		bit = (*i - sizeof(*len)) % (sizeof(char) * 8);
		printf("char2bit *i == %zu\nsizeof(*len) * 8 == %zu\n", *i, sizeof(*len) * 8);
		printf("entering char2bit\nbit = %i\ni for str[i] == %zu\n", bit, *i - sizeof(*len) * 8);
		printf("*str[0] == %d\n", *str[0]);
		ft_inspectstr(sig, i, len, unitsize, str);
	//	*str[ /**i - (sizeof(*len) * 8)*/ 0] = 'a'; // *str[*i - sizeof(*len) * 8] | (sig - SIGUSR1) << bit;
		*str[0] = 'b';
		*str[1] = 'b';
		*str[2] = 'c';
		*str[3] = 'd';
		*str[4] = 'e';
		*str[5] = 'f';
		*str[6] = 'g';
		*str[7] = 'h';
		printf("*str: %s\n", *str);

		//if received last bit of char, check if it was a '\0' which indicates end of the operation.
		if (bit == 7 && *str[*i - sizeof(*len) * 8] == '\0')
			return (1);
	}
	return (0);
}

static int	ft_rcv_bits(int sig, siginfo_t *sinfo)
{
	static char		*str = NULL;
	static size_t	len = 0;
	static size_t	i = 0;
	static int		b2l_status = 2;

	printf("b2lstatus = %i\n", b2l_status);
	if ((b2l_status = ft_bits2len(sig, &i, &len, sizeof(len) * 8, &str)) == 1)
	{
		printf("Received string length is: %lu\nString: %s\nEND.\n", len, str);
		free(str);
		str = NULL;
		len = 0;
		i = 0;
		b2l_status = 2;
	}
	++i;
	printf("b2lstatus = %i\n\n", b2l_status);
	printf("str = %s\n", str);
	return (0);
}

static void	fn_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
/*	if (sig == SIGUSR1)
	{
		printf("0 Signal %d received from PID %d\n", sig, sinfo->si_pid);
	}
	else if (sig == SIGUSR2)
	{
		printf("1 Signal %d received from PID %d\n", sig, sinfo->si_pid);
	}
	*/
	ft_rcv_bits(sig, sinfo);
	(void)ptr;
	return ;
}

int	main(void)
{
	struct sigaction	s_sa = {0};
	
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sa_sigaction = fn_sigusr;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL); 
	printf("Server PID: %i\n", getpid());
	printf("Waiting to receive signals\n");
//	printf("sizeof(*len) == %zu\nsizeof(size_t) == %zu\n", sizeof(*len), sizeof(size_t));
	while (1)
	{
		pause();
	}
	return (0);
}
