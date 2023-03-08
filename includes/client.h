/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:51:20 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/08 17:53:21 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		 //write
#include <signal.h>		 //kill
#include <sys/types.h>	 //pid_t
#include <stdlib.h>		 //EXIT_FAILURE, EXIT_SUCCESS
#include "libft.h"		 //ft_strlen

#define USLP 100

static int	fn_checkerr(int argc, char **argv);
static int	ft_snd_unit_bits(pid_t pid, int unitsize, size_t unit);
static int	ft_send(pid_t pid, char *str);
