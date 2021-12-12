/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:06:05 by tkano             #+#    #+#             */
/*   Updated: 2021/12/13 07:28:53 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	command_loop(s_stack **a, s_stack **b, s_info **info, int cmd)
{
	if (cmd == PA)
		return (add_ans_pa(a, b, info));
	if (cmd == PB)
		return (add_ans_pb(a, b, info));
	if (cmd == SA)
		return (add_ans_sa(a, info));
	if (cmd == SB)
		return (add_ans_sb(b, info));
	if (cmd == SS)
		return (add_ans_ss(a, b, info));
	if (cmd == RA)
		return (add_ans_ra(a, b, info));
	if (cmd == RB)
		return (add_ans_rb(a, b, info));
	if (cmd == RR)
		return (add_ans_rr(a, b, info));
	if (cmd == RRA)
		return (add_ans_rra(a, b, info));
	if (cmd == RRB)
		return (add_ans_rrb(a, b, info));
	if (cmd == RRR)
		return (add_ans_rrr(a, b, info));
	return (SUCCESS);
}