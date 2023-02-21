/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:26:18 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 15:29:55 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_pf_d(t_vars *vars)
{
	long	nbr;

	nbr = va_arg(vars->args, int);
	if (nbr < 0)
	{
		nbr *= -1;
		if (ft_print_char(vars, '-') == -1)
			return (-1);
	}
	return (ft_print_unsint(vars, nbr));
}

int	ft_pf_u(t_vars *vars)
{
	long	nbr;

	nbr = va_arg(vars->args, unsigned int);
	return (ft_print_unsint(vars, nbr));
}

int	ft_print_unsint(t_vars *vars, long nbr)
{
	int		pos;
	char	digit[10];

	pos = 0;
	while (nbr >= 10)
	{
		digit[pos++] = nbr % 10 + '0';
		nbr /= 10;
	}
	digit[pos] = nbr % 10 + '0';
	while (pos >= 0)
		if (ft_print_char(vars, digit[pos--]) == -1)
			return (-1);
	return (vars->lastreturn);
}
