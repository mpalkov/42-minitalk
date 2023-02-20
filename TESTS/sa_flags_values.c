/*
https://man7.org/linux/man-pages/man2/sigaction.2.html

sigaction flags
sa_flags specifies a set of flags which modify the behavior of the signal.
		It is formed by the bitwise OR of zero or more of thhe folowing flags
		(MACROS)

-- The macros are supposedly int numbers,
	but on my system MAC, it appears, there are 7 flags (see bellos)
	and the range is 1 - 64 so it can fit in a char (in 8 bits).
   	Each flag is one, and only one - "1" bit in this 8-bit number.
	It's using one bit to identify each flag.
	Like this, you can use multiple flags merging them with bitwise OR,
	for example:
   				sa1.sa_flags = SA_RESTART | SA_SIGINFO;
				the value of sa1.sa_flags will be 66
					(64 | 2 = 66);
*/

#include <signal.h>
#include <stdio.h>


int main(void)
{
    printf("SA_ONSTACK:				%d\n", SA_ONSTACK);
    printf("SA_RESTART:				%d\n", SA_RESTART);
    printf("SA_RESETHAND:				%d\n", SA_RESETHAND);
    printf("SA_NOCLDSTOP:				%d\n", SA_NOCLDSTOP);
    printf("SA_NODEFER:				%d\n", SA_NODEFER);
    printf("SA_NOCLDWAIT:				%d\n", SA_NOCLDWAIT);
    printf("SA_SIGINFO:				%d\n\n\n", SA_SIGINFO);
    printf("SA_SIGINFO | SA_RESTART:		%d\n", SA_SIGINFO | SA_RESTART);
    return (0);
}

/*
 OUTPUT:

SA_ONSTACK:		1
SA_RESTART:		2
SA_RESETHAND:	4
SA_NOCLDSTOP:	8
SA_NODEFER:		16
SA_NOCLDWAIT:	32
SA_SIGINFO:		64

SA_SIGINFO | SA_RESTART: 66 (64 | 2 = 66)
*/
