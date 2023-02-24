/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:34:58 by mpalkov           #+#    #+#             */
/*   Updated: 2023/02/24 14:38:44 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//	you can access a global variable from a function  withut declaring it there
//  or receiving it as an argument. You can access it with . because it is
//  "in the same scope as any function"
//  ctrl.len = 55;
//  
//  UNNECESSARY:
//  You can receive it as t_control *ctrl argument and you can access it 
//  as ctrl->len = 0;
//  AND TOO as vars.len = 0;


typedef struct  s_control
{
    char    *str;
    size_t  len;
    size_t  i;
    int     status;
    pid_t   initpid;

}   t_control;

t_control   vars;

void    ft_resetvars(t_control *ctrl)
{
    ctrl->str = NULL;
    ctrl->len = 0;
    ctrl->i = 0;
    ctrl->status = 2;
    ctrl->initpid = -42;
    return ;
}

void  ft_fn(void)
{
    vars.len = 42;
}

void    ft_fn2(t_control *ptr)
{
    ptr->i = 999;
    vars.i = 1;
}

void    ft_fn3(t_control c)
{
    c.status = -123;
    vars.initpid = 0;
}

int main(void)
{
    ft_resetvars(&vars);
    ft_fn2(&vars);
    ft_fn3(vars);
    ft_fn();
    return (0);
}
