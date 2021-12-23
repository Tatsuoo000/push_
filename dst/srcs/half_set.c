/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:58:57 by tkano             #+#    #+#             */
/*   Updated: 2021/12/23 12:46:38 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	search_min_value(t_ft_stack **v, t_info **info)
{
	int			j;
	t_ft_stack	*tmp;

	tmp = *v;
	if (tmp->value == DUMMY)
		return (FALSE);
	j = tmp->value;
	while (j != (*info)->min_value && j - 1 == tmp->next->value && \
		tmp->value != DUMMY && tmp->next->value != DUMMY)
	{
		--j;
		tmp = tmp->next;
	}
	if ((*info)->min_value == j)
		return (TRUE);
	return (FALSE);
}

int	b_half_set(t_info **info, int *start, int middle, int end)
{
	int	i;
	int	cmd;

	i = end;
	while (*start < end && middle < i)
	{
		if ((*info)->b->value >= middle)
			--i;
		if (search_min_value(&((*info)->b), info))
		{
			if (pa_ra_min(info, start))
				return (ERROR);
		}
		else
		{
			cmd = RB;
			if ((*info)->b->value >= middle)
				cmd = PA;
			if (command_loop(info, 1, cmd))
				return (ERROR);
			--end;
		}
	}
	return (SUCCESS);
}

int	first_half_set(t_info **info, int median)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (*info)->size && j < median)
	{
		if ((*info)->a->value >= median)
		{
			if (add_ans_ra(info))
				return (ERROR);
		}
		else
		{
			++j;
			if (add_ans_pb(info))
				return (ERROR);
		}
		++i;
	}
	return (SUCCESS);
}
