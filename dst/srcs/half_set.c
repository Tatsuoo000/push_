/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:58:57 by tkano             #+#    #+#             */
/*   Updated: 2021/12/22 11:11:25 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int search_min_value(s_stack **v, s_info **info)
{
	int	j;
	s_stack *tmp;

	tmp = *v;
	if (tmp->value == DUMMY)
		return (False);
	j = tmp->value;
	//printf("b_half value: %ld\n", tmp->value);
	while (j != (*info)->min_value && j - 1 == tmp->next->value && tmp->value != DUMMY && tmp->next->value != DUMMY)
	{
		--j;
		tmp = tmp->next;
		//printf("b_half value: %ld min_value: %ld j: %d\n", tmp->value, (*info)->min_value, j);
	}
	if ((*info)->min_value == j)
		return (True);
	return (False);

}

int	b_half_set(s_stack **a, s_stack **b, s_info **info, int *start, int middle, int end)
{
	int i;
	int	cmd;

	i = end;
	//printf("b_half_set start: %d, middle %d, end %d\n", *start, middle, end);
	while (*start < end && middle < i)
	{
		if ((*b)->value >= middle)
			--i;
		if (search_min_value(b, info))
		{
			if (pa_ra_min(a, b, info, start))
				return (ERROR);
		}
		else
		{
			cmd = RB;
			if ((*b)->value >= middle)
				cmd = PA;
			if (command_loop(a, b, info, 1, cmd))
				return (ERROR);
			--end;
		}
	}
	//printf("b_half_set start: %d\n", *start);
	//put_stack(*a);
	return (SUCCESS);
}

int first_half_set(s_stack **a, s_stack **b, s_info **info, int median)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	//printf("size: %ld, median: %d\n", (*info)->size, median);
	while (i < (*info)->size && j < median)
	{
		//printf("size: %ld, median: %d\n", (*info)->size, median);
		if ((*a)->value >= median)
		{
			if (add_ans_ra(a, info))
				return (ERROR);
		}
		else
		{
			++j;
			if (add_ans_pb(a, b, info))
				return (ERROR);
		}
		++i;
	}
	//printf("halfset\n");
	return (SUCCESS);
}
