#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

typedef struct s_var
{
	char	*str;
}	t_var;

static int ft_bits2len(int sig, size_t *i, char *len, int unitsize, char **str)
{
	static int	bit = 0;
	//first unitsize will be size_t (64 bits), so 0 to 64 it will be this if
	printf("*i == %zu\n", *i);
	if (*i < (sizeof(*len) * 8))
	{
		*len = sig << *i | *len;
		printf("len = %d\n", *len);
	}
	if (*i == (sizeof(*len) * 8 - 1))
	{
		printf("\nmalloc len = %d\n", *len);
		if (!(*str = malloc((*len + 1) * sizeof(char))))
			return (-1);
		printf("*str = %p, **str = %p, calloc = %lu\n", *str, str, (*len + 1) * sizeof(char));
	}
	else if (*i >= sizeof(*len) * 8)
	{
		bit = (*i - sizeof(*len)) % (sizeof(char) * 8);
		printf("entering char2bit\nbit = %i\ni for str[i] == %lu\n", bit, *i - sizeof(*len) * 8);
		printf("char2bit *i == %zu\nsizeof(*len) * 8 == %lu\n", *i, sizeof(*len) * 8);
		printf("*str[0] == %d\n", *str[0]);
		(*str)[*i - (sizeof(*len) * 8)] = ((*str)[*i - sizeof(*len) * 8]) | ((sig - SIGUSR1) << bit);
	//	(*str)[0] = 'x';
	//	(*str)[1] = 'y';
	//	(*str)[2] = 0;
		printf("*str: %s\n", *str);

		//if received last bit of char, check if it was a '\0' which indicates end of the operation.
		if (bit == 7 && (*str)[*i - sizeof(*len) * 8] == '\0')
			return (1);
	}
	return (0);
}


static int	ft_rcv_bits(int sig)
{
	static char		*str;
	static char		len = 0;
	static size_t	i = 0;
	static int		b2l_status = 2;

	printf("b2lstatus = %i\n", b2l_status);
	if ((b2l_status = ft_bits2len(sig, &i, &len, sizeof(len) * 8, &str)) == 1)
	{
		printf("Received string length is: %d\nString: %s\nEND.\n", len, str);
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


void ft_send(char *str)
{
	int	i = 0;

	while (str[i])
		ft_rcv_bits((int)(str[i++] - '0'));
	return ;
}


int	main(int argc, char **argv)
{
	char *bitseq = "01000000110001101111011000000000";

	ft_send(bitseq);

	return (0);
}


/* CLIENT
static int	ft_snd_unit_bits(int unitsize, size_t unit)
{
	char	b = 0;
	int		bit = 0;

	printf("src:	%lu\n----\nbits:	", unit);
	while (bit < unitsize)
	{
		b = (unit >> bit) & 1;
		if (b == 1)
			kill(pid, SIGUSR2);
		else if (b == 0)
			kill(pid, SIGUSR1);
		printf("%i", b);
		++bit;
		USLP
	}
	printf("\n\n");
	return (0);
}

static int	ft_send(pid_t pid, char *str)
{
	size_t	i = 0;
	//sendlen
	ft_snd_unit_bits(sizeof(size_t) * 8, strlen(str));
	//sendstr
	while (str[i])
		ft_snd_unit_bits(sizeof(str[i]) * 8, str[i++]);
	//send '\0'
	if (str[i] == '\0')
		ft_snd_unit_bits(sizeof(str[i]) * 8, str[i]);
	return (0);
}
*/
