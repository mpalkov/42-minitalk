/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_ptr_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:28:06 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 15:29:39 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_pf_x(t_vars *vars)
{
	unsigned int	nbr;

	nbr = va_arg(vars->args, unsigned int);
	if (ft_print_hex_case(vars, (unsigned long long)nbr) == -1)
		return (-1);
	return (vars->lastreturn);
}	

// This is a recursive function. This way I can print number directly
// in the right order wihout the need to save number by number in a 
// intermediate string and then print it in reverse order.
// vars->caseflag is char 'a' or 'A' so I can use the same funcion for %x and %X
int	ft_print_hex_case(t_vars *vars, unsigned long long nbr)
{
	if (nbr >= 16)
	{
		if (ft_print_hex_case(vars, nbr / 16) == -1)
			return (-1);
		if (ft_print_hex_case(vars, nbr % 16) == -1)
			return (-1);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_print_char(vars, '0' + nbr) == -1)
				return (-1);
		}
		else if (nbr <= 15)
		{
			if (ft_print_char(vars, vars->caseflag + nbr - 10) == -1)
				return (-1);
		}
	}
	return (vars->lastreturn);
}

int	ft_pf_p(t_vars *vars)
{
	unsigned long long	nbr;

	nbr = va_arg(vars->args, unsigned long long);
	if (nbr == 0)
	{
		if (ft_print_str(vars, "0x0") == -1)
			return (-1);
	}
	else
	{
		vars->caseflag = 'a';
		if (ft_print_str(vars, "0x") == -1)
			return (-1);
		if (ft_print_hex_case(vars, nbr) == -1)
			return (-1);
	}
	return (vars->lastreturn);
}
