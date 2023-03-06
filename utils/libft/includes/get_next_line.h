/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:24:28 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/15 14:25:56 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)100
# endif

char	*get_next_line(int fd);
char	*ft_strchr_nosegf(char *s, int c);
char	*ft_strjoin_free_s1(char *s1, char *s2);
void	*ft_char_freenull(char **ptr);

#endif
