/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:06:05 by tkano             #+#    #+#             */
/*   Updated: 2021/12/23 12:20:12 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa_ra_min(t_info **info, int *start)
{
	int	i;

	i = 0;
	while ((*info)->a->value != DUMMY && \
		(*info)->a->value != (*info)->min_value)
	{
		if (add_ans_pa(info))
			return (ERROR);
		++i;
	}
	if (command_loop(info, i, RA))
		return (ERROR);
	*start += i;
	(*info)->min_value += i;
	return (SUCCESS);
}

int	pa_ra_set(t_info **info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (add_ans_pa(info))
			return (ERROR);
		if (add_ans_ra(info))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	command_exec(t_info **info, int cmd)
{
	if (cmd == PA)
		return (add_ans_pa(info));
	if (cmd == PB)
		return (add_ans_pb(info));
	if (cmd == SA)
		return (add_ans_sa(info));
	if (cmd == SB)
		return (add_ans_sb(info));
	if (cmd == RA)
		return (add_ans_ra(info));
	if (cmd == RB)
		return (add_ans_rb(info));
	if (cmd == RRA)
		return (add_ans_rra(info));
	if (cmd == RRB)
		return (add_ans_rrb(info));
	return (SUCCESS);
}

int	command_loop(t_info **info, int loop, int cmd)
{
	int	i;

	i = 0;
	while (i < loop)
	{
		if (command_exec(info, cmd))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}
