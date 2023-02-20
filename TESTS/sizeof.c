/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:35:37 by mpalkov           #+#    #+#             */
/*   Updated: 2023/01/27 11:50:57 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("My system configuration:\n");
	printf("sizeof size_t:	%lu\n", sizeof(size_t));
	printf("sizeof ssize_t:	%lu\n", sizeof(ssize_t));
	printf("sizeof int:	%lu\n", sizeof(int));
	printf("sizeof char:	%lu\n", sizeof(char));
	printf("sizeof long:	%lu\n", sizeof(long));
	return (0);
}
