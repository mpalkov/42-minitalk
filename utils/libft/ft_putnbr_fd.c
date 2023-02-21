/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:21:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/23 17:32:57 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	ft_initvars(int *pos, int *len, long *nbr, int n)
{
	*pos = 0;
	*nbr = n;
	*len = 0;
}

int	ft_putnbr_fd(int n, int fd)
{
	int		pos;
	int		len;
	long	nbr;
	char	dec[10];

	ft_initvars(&pos, &len, &nbr, n);
	if (nbr < 0)
	{
		nbr *= -1;
		len = 1;
		if (write (fd, "-", sizeof(char)) != sizeof(char))
			return (-1);
	}
	while (nbr >= 10)
	{
		dec[pos++] = nbr % 10 + '0';
		nbr /= 10;
	}
	len = len + pos + 1;
	dec[pos] = nbr % 10 + '0';
	while (pos >= 0)
		if (write(fd, &(dec[pos--]), sizeof(char)) != sizeof(char))
			return (-1);
	return (sizeof(char) * len);
}

// This function Outputs the integer ’n’ to the given file descriptor.
//
// passing int n to long nbr and working with this, No lines for special
// case of max negative int are needed, as when multiplying by -1 it does
// not exceeds the max value of int.
