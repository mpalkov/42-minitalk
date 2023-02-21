/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_freenull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:47:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/10 14:50:15 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ptr_freenull(void *x_ptr)
{
	void	**ptr;

	ptr = (void **)x_ptr;
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}

// this function serves to free pointer of any type
// (previously created with malloc/calloc...) and set it to NULL;

//USE:
/* int	main(void)
{
	char	*c;
	int		*i;

	i = malloc(8);
	c = malloc(8);
	ft_ptr_freenull(&c);
	ft_ptr_freenull(&i);
	return (0);
} */
