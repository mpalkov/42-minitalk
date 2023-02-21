/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:59:26 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/13 12:13:54 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Printable ASCII in man isprint are the following numbers:
// decimal set 32 sp to 126 ~

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
