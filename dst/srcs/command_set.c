/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:06:05 by tkano             #+#    #+#             */
/*   Updated: 2021/12/15 19:01:21 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa_ra_min(s_stack **a, s_stack **b, s_info **info, int *start)
{
	int	i;

	i = 0;
	while ((*a)->value != DUMMY && (*a)->value != (*info)->min_value)
	{
		if (add_ans_pa(a, b, info))
			return (ERROR);
		++i;
	}
	if (command_loop(a, b, info, i, RA))
		return (ERROR);
	*start += i;
	(*info)->min_value += i;
	return (SUCCESS);
}

int	pa_ra_set(s_stack **a, s_stack **b, s_info **info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (add_ans_pa(a, b, info))
			return (ERROR);
		if (add_ans_ra(a, info))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	command_exec(s_stack **a, s_stack **b, s_info **info, int cmd)
{
	if (cmd == PA)
		return (add_ans_pa(a, b, info));
	if (cmd == PB)
		return (add_ans_pb(a, b, info));
	if (cmd == SA)
		return (add_ans_sa(a, info));
	if (cmd == SB)
		return (add_ans_sb(b, info));
	if (cmd == RA)
		return (add_ans_ra(a, info));
	if (cmd == RB)
		return (add_ans_rb(b, info));
	if (cmd == RRA)
		return (add_ans_rra(a, info));
	if (cmd == RRB)
		return (add_ans_rrb(b, info));
	return (SUCCESS);
}

int	command_loop(s_stack **a, s_stack **b, s_info **info, int loop, int cmd)
{
	int	i;

	i = 0;
	while (i < loop)
	{
		if (command_exec(a, b, info, cmd))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}