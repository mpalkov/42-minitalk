#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

// esto esta funcionando!!!! OK OK OK
//

static int ft_bits2len(int sig, size_t *i, char *len, int unitsize, char **str)
{
    //strpos - position in the char * array.
    //pos_bit - bit number in the strpos position.
    static int    strpos = 0;
    static int    pos_bit = 0;
    //first unitsize will be size_t (64 bits), so 0 to 64 it will be this if
    printf("*i == %zu\n", *i);
    if (*i < (sizeof(*len) * 8))
    {
        *len = sig << *i | *len;
        printf("len = %d\n", *len);
    }
	// if counter arrived to complete the first bites set which makes the len, create malloc of len length.
    if (*i == (sizeof(*len) * 8 - 1))
    {
        printf("\nmalloc len = %d\n", *len);
        if (!(*str = calloc((*len + 1), sizeof(char))))
            return (-1);
        printf("*str = %p, **str = %p, calloc = %lu\n", *str, str, (*len + 1) * sizeof(char));
    }

	//afterwards this will construct each str char with its bits untill final '\0' is constructed
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

void ft_send(char *str)
{
    char  *s;
    static char        *str1;
    static char        len = 2;
    static size_t     i = 7;
    static int        b2l_status = 2;
    
    while (str[i])
    {
        s = &str[i];
        if ((b2l_status = ft_bits2len(str[i] - '0', &i, &len, sizeof(len) * 8, &str1)) == 1)
        {
            printf("Received string length is: %d\nString: %s\nEND.\n", len, str1);
            free(str1);
            str1 = NULL;
            len = 0;
            i = 0;
            b2l_status = 2;
			break;
        }
    ++i;
    printf("b2lstatus = %i\n\n", b2l_status);
    printf("str = %s\n", str);
    }
    return ;
}


int    main(void)
{
    char *bitseq = "01000000110001101111011000000000";
    int charsize = sizeof(char);

    ft_send(bitseq);

    return (0);
}
