/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:46 by mpalkov           #+#    #+#             */
/*   Updated: 2023/03/10 11:34:08 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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

static int	ft_rcvbits(int sig);
static void	ft_sigusr(int sig, siginfo_t *sinfo, void *ptr);
static int	ft_siginit(struct sigaction *s_sa);
static int	ft_loop(void);
int			ft_checkpid(siginfo_t *info);
void		ft_free_exit(void);
int			ft_restartsrv(void);
int			ft_printpid();
int			ft_timeoutcheck(void);
void		ft_resetvars(void);

#endif
