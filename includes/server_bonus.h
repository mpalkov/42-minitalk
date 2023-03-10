/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:53:37 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 14:55:04 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_control
{
	char	*str;
	size_t	len;
	ssize_t	i;
	int		status;
	pid_t	initpid;
	size_t	strpos;
	int		pos_bit;
	int		sig;
	int		sig_processed;

}	t_control;

int		ft_checkpid(siginfo_t *info);
int		ft_siginit(struct sigaction *s_sa);
void	ft_sigusr(int sig, siginfo_t *sinfo, void *ptr);
void	ft_free_exit(void);
int		ft_restartsrv(void);
int		ft_printpid(void);
int		ft_timeoutcheck(void);
void	ft_resetvars(void);

#endif
