/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 15:28:59 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
// #include <libft.h> is present in the ft_printf.h file so it will be loaded

static int	ft_printcheck(t_vars *vars)
{
	if (*vars->format == '%')
		return (ft_pf_perc(vars));
	else if (*vars->format == 'c')
		return (ft_pf_c(vars));
	else if (*vars->format == 's')
		return (ft_pf_s(vars));
	else if (*vars->format == 'd' || *vars->format == 'i')
		return (ft_pf_d(vars));
	else if (*vars->format == 'u')
		return (ft_pf_u(vars));
	else if (*vars->format == 'x')
	{
		vars->caseflag = 'a';
		return (ft_pf_x(vars));
	}
	else if (*vars->format == 'X')
	{
		vars->caseflag = 'A';
		return (ft_pf_x(vars));
	}
	else if (*vars->format == 'p')
		return (ft_pf_p(vars));
	return (0);
}

// This function goes through the string char by char and prints char by char
// from the string, or checks the format modifier if '%' found in the string.
// ft_strchr returns NULL if no match found or &str[i] if a match is found.
static int	ft_gothrough(t_vars *vars)
{
	while (vars->strn[vars->pos_s])
	{
		vars->format = ft_strchr((const char *)VALIDFORMAT,
				(int)vars->strn[vars->pos_s + 1]);
		if (vars->strn[vars->pos_s] == '%' && !vars->format)
			return (-1);
		else if (vars->strn[vars->pos_s] == '%' && vars->format)
		{
			if (ft_printcheck(vars) == -1)
				return (-1);
			vars->pos_s++;
		}
		else if (vars->strn[vars->pos_s] != '%')
		{
			if (ft_putchar(vars->strn[vars->pos_s]) == -1)
				return (-1);
			vars->printcount++;
		}
		vars->pos_s++;
	}
	return (0);
}

static void	ft_initvars(t_vars *vars, const char *str)
{
	vars->printcount = 0;
	vars->pos_s = 0;
	vars->strn = (char *)str;
}

// sys printf returns -1 if (!str)
int	ft_printf(const char *str, ...)
{
	t_vars	vars;

	if (!str)
		return (-1);
	ft_initvars(&vars, str);
	va_start(vars.args, str);
	if (ft_gothrough(&vars) == -1)
	{
		va_end(vars.args);
		return (-1);
	}
	va_end(vars.args);
	return (vars.printcount);
}

// One of the core functions is ft_print_char
// which basically prints single char and handles errors
// and final length to be returned by ft_printf.
//
// The aim was to make the code modular (within my actual capacities),
// not repeating code so if a change needs to be done,
// it can be done in a single place.
// Another goal was to make things more human-readable. Using NULL,
// macros like STDOUT_FILENO, etc. instead of bare numbers, for example.
//
// Error Handling:
// Eevery function returns int, so I can control errors by returning -1
// and calling the functions in a
//  if (ft_function(args) == -1)
//  	return (-1);
//
//	removed vars->validformat = "cspdiuxX%".
//	validformat is defined in ft_printf.h now
