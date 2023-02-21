/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:27:38 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/18 15:00:23 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_calloc0(size_t nmbyte, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	ptr = malloc(nmbyte * size);
	if (ptr == 0)
		return (0);
	while (i < nmbyte * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

static void	ft_defsign0(int *sign, long *d, int n, int *len)
{
	*len = 0;
	*sign = 0;
	*d = n;
	if (*d < 0)
	{
		*sign = 1;
		*d *= -1;
	}
	return ;
}

char	*ft_itoa(int n)
{
	int		len;
	char	res[10];
	char	*num;
	int		sign;
	long	d;

	ft_defsign0(&sign, &d, n, &len);
	while (d >= 10)
	{
		res[len++] = (char)(d % 10 + '0');
		d /= 10;
	}
	res[len] = (char)(d % 10 + '0');
	num = (char *)ft_calloc0(sizeof(char), (size_t)(len + sign) + 2);
	if (!num)
		return (0);
	n = len;
	while (len >= 0)
	{
		num[n - len + sign] = res[len];
		len--;
	}
	if (sign == 1)
		num[0] = '-';
	return (num);
}

// itoa
// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument. Negative numbers must be handled.
// Returns The string representing the integer.
// Returns NULL if the allocation fails.

// ft_defsign0 (define the integer's sign) checks if the n number
// is negative and sets the sign variable accordingly.
// I have added initialization of len variable here to reduce length
// of the main function.
