/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:45:11 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 20:00:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_ra(t_ft_stack **a)
{
	long	tmp;

	while ((*a)->prev->prev->value != DUMMY)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->prev->value;
	(*a)->prev->value = DUMMY;
	(*a)->prev->prev->value = tmp;
}

int	add_ans_ra(t_info **info)
{
	do_ra(&((*info)->a));
	if (add_stack(&((*info)->ans), RA))
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_rb(t_info **info)
{
	do_ra(&((*info)->b));
	if (add_stack(&((*info)->ans), RB))
		return (ERROR);
	return (SUCCESS);
}
