/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:03:26 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 15:29:26 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_char(t_vars *vars, char c)
{
	vars->lastreturn = ft_putchar (c);
	if (vars->lastreturn == -1)
		return (-1);
	else
		vars->printcount += vars->lastreturn;
	return (vars->lastreturn);
}

int	ft_pf_c(t_vars *vars)
{
	int	c;

	c = va_arg(vars->args, int);
	return (ft_print_char(vars, (char)c));
}

int	ft_print_str(t_vars *vars, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_print_char(vars, str[i++]) == -1)
			return (-1);
	}
	return (vars->lastreturn);
}

int	ft_pf_perc(t_vars *vars)
{
	return (ft_print_char(vars, '%'));
}

int	ft_pf_s(t_vars *vars)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(vars->args, char *);
	if (!s)
	{
		if (ft_print_str(vars, "(null)") == -1)
			return (-1);
		else
			return (vars->lastreturn);
	}
	while (s[i])
	{
		if (ft_print_char(vars, s[i]) == -1)
			return (-1);
		i++;
	}
	return (vars->lastreturn);
}
