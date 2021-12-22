/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:37:56 by tkano             #+#    #+#             */
/*   Updated: 2021/07/13 17:56:30 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	finish_program(int flag, s_stack **a, s_stack **b, s_info **info)
{
	clear_stack(a);
	clear_stack(b);
	//clear_stack(&((*info)->a));
	//clear_stack(&((*info)->b));
	clear_stack(&((*info)->ans));
	free(*info);
	if (flag == ERROR)
	{
		put_error();
		return (ERROR);
	}
	else
		return (SUCCESS);
}
