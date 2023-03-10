/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:04 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 11:42:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_control	vars;

int	ft_checkpid(siginfo_t *info)
{
	if (info->si_pid == vars.initpid)
		return (0);
	else if (vars.i == -1 && vars.initpid == -42)
	{
		vars.initpid = info->si_pid;
		return (0);
	}
	return (-1);
}