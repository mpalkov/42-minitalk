/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:51:51 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 14:53:27 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include <unistd.h>	//write
# include <signal.h>	//kill
# include <sys/types.h>	//pid_t
# include <stdlib.h>	//EXIT_FAILURE, EXIT_SUCCESS
# include "libft.h"		//ft_strlen

# define USLP 100

static int	fn_checkerr(int argc, char **argv);
static int	ft_snd_unit_bits(pid_t pid, int unitsize, size_t unit);
static int	ft_send(pid_t pid, char *str);

#endif
