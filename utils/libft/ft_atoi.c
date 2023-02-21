/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:59:17 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/23 15:28:57 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	ifnegative;
	int	c;

	i = 0;
	j = 0;
	ifnegative = 1;
	c = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		ifnegative = -1;
	if ((str[i] == '+' || str[i] == '-') \
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i + j] != 0 && str[i + j] >= '0' && '9' >= str[i + j])
			j++;
	while (--j >= 0)
		c = c * 10 + (str[i++] - '0');
	return (c * ifnegative);
}
