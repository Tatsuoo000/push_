/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:05:33 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 19:56:55 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_rra(s_stack **a)
{
	long	tmp;

	while ((*a)->value != DUMMY)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->prev->value;
	(*a)->value = tmp;
	(*a)->prev->value = DUMMY;
}

int	add_ans_rra(s_info **info)
{
	do_rra(&((*info)->a));
	if (add_stack(&((*info)->ans), RRA))
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_rrb(s_info **info)
{
	do_rra(&((*info)->b));
	if (add_stack(&((*info)->ans), RRB))
		return (ERROR);
	return (SUCCESS);
}
