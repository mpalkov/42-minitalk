/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/08 20:08:52 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include <signal.h> //signals
#include <stdio.h>
#include <stdlib.h> //malloc, free

//incluir libft y ft_printf y sustituir funciones de sistema

static int ft_inspectstr(int sig, size_t *i, size_t *len, int unitsize, char **str)
{
	(void)sig;
	return (0);
}

//sig argument is (sig - SIGUSR1) so it will be (int)1 or 0;
static int ft_bits2len(int sig, size_t *i, size_t *len, char **str)
{
	//strpos - position in the char * array.
	//pos_bit - bit number in the strpos position.
	static int	strpos;
	static int	pos_bit;

	strpos = 0;
	pos_bit = 0;
	//first unitsize will be size_t (64 bits), so 0 to 64 it will be this if()
	printf("*i == %zu\nsig == %d", *i, sig);
	if (*i < (sizeof(*len) * 8))
	{
		*len = sig << *i | *len;
		printf("len = %zu\n", *len);
	}
	// if counter arrived to complete the first bites-set which makes the len, create malloc of len length.
	if (*i == (sizeof(*len) * 8 - 1))
	{
		printf("\nmalloc len = %zu\n", *len);
		if (!(*str = calloc(*len + 1, sizeof(char))))
			return (-1);
		printf("*str = %p, **str = %p, calloc = %zu\n", *str, str, (*len + 1) * sizeof(char));
	}
	//afterwards this will construct each str char with its bits untill final '\0' is detected after its' creation
	else if (*i >= sizeof(*len) * 8)
	{
		// strpos counts in which position of our string are we currently working
		strpos = (*i - sizeof(*len) * 8) / (sizeof(char) * 8);
		// pos_bit indicates, which is the currently received bit of our current byte (strpos)
		pos_bit = (*i - sizeof(*len) * 8) % (sizeof(char) * 8);
		printf("entering char2bit\nbit = %i\nstrpos == %d\n", pos_bit, strpos);
		printf("char2bit *i == %zu\nsizeof(*len) * 8 == %lu\n", *i, sizeof(*len) * 8);
		printf("*str[strpos] == %d\n", (*str)[strpos]);
		//add the current bit to the current byte.
		(*str)[strpos] = ((*str)[strpos]) | ((sig) << pos_bit);
		printf("*str: %s\n", *str);
		//if received last bit of char, check if it was a '\0' which indicates end of the operation.
		if (pos_bit == 7 && (*str)[strpos] == '\0')
			return (1);
	}
	return (0);
}

static void	fn_sigusr(int sig, siginfo_t *sinfo, void *ptr)
{
	static char		*str = NULL;
	static size_t	len = 0;
	static size_t	i = 0;
	static int		b2l_status = 2;
	(void)ptr;

	//fn_initchecks
	printf("b2lstatus = %i\n", b2l_status);
	if ((b2l_status = ft_bits2len(sig - SIGUSR1, &i, &len, &str)) == 1)
	{
		printf("\n\n***************\nReceived string length is: %lu\nString: %s\nEND.\n************\n", len, str);
		free(str);
		str = NULL;
		len = 0;
		i = 0;
		b2l_status = 2;
	}
	else 
	{
		++i;
		printf("b2lstatus = %i\n\n", b2l_status);
		printf("str = %s\n", str);
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
	printf("Server PID: %i\n", getpid());
	printf("Waiting to receive signals\n");
//	printf("sizeof(*len) == %zu\nsizeof(size_t) == %zu\n", sizeof(*len), sizeof(size_t));
	while (1)
	{
		pause();
	}
	return (0);
}
