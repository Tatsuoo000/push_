/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:08:02 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:13:11 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_sa(t_ft_stack **a)
{
	long	tmp;

	while ((*a)->prev->value != DUMMY)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
}

int	add_ans_sa(t_info **info)
{
	do_sa(&((*info)->a));
	if (add_stack(&((*info)->ans), SA))
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_sb(t_info **info)
{
	do_sa(&((*info)->b));
	if (add_stack(&((*info)->ans), SB))
		return (ERROR);
	return (SUCCESS);
}
