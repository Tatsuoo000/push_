/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:45:42 by tkano             #+#    #+#             */
/*   Updated: 2021/12/22 11:39:12 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	b_qs4(s_stack **a, s_stack **b, s_info **info, int start, int end)
{
	if (end - start == 2)
	{
		(*info)->min_value += 2;
		if ((*b)->value == start)
		{
			if (pa_ra_set(a, b, info, 2))
				return (ERROR);
		}
		else
		{
			if (command_loop(a, b, info, 2, PA))
				return (ERROR);
			if (command_loop(a, b, info, 2, RA))
				return (ERROR);
		}
	}
	else
	{
		(*info)->min_value += 1;
		if (pa_ra_set(a, b, info, 1))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_qs3(s_stack **a, s_stack **b, s_info **info, int start)
{
	if ((*b)->next->value == start)
	{
		if (command_loop(a, b, info, 2, PA))
			return (ERROR);
		if (command_loop(a, b, info, 1, RA))
			return (ERROR);
		if (command_loop(a, b, info, 1, PA))
			return (ERROR);
		if (command_loop(a, b, info, 2, RA))
			return (ERROR);
	}
	else
	{
		if (command_loop(a, b, info, 3, PA))
			return (ERROR);
		if (command_loop(a, b, info, 3, RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_qs2(s_stack **a, s_stack **b, s_info **info, int start)
{
	if ((*b)->next->value == start)
	{
		if (command_loop(a, b, info, 2, PA))
			return (ERROR);
		if (command_loop(a, b, info, 2, RA))
			return (ERROR);
		if (pa_ra_set(a, b, info, 1))
			return (ERROR);
	}
	else
	{
		if (command_loop(a, b, info, 1, RB))
			return (ERROR);
		if (command_loop(a, b, info, 2, PA))
			return (ERROR);
		if (command_loop(a, b, info, 1, RA))
			return (ERROR);
		if (command_loop(a, b, info, 1, PA))
			return (ERROR);
		if (command_loop(a, b, info, 2, RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_quicksort(s_stack **a, s_stack **b, s_info **info, int start, int end)
{
	if (end - start == 3)
	{
		(*info)->min_value += 3;
		if ((*b)->value == start && (*b)->next->value == start + 1)
		{
			if (pa_ra_set(a, b, info, 3))
				return (ERROR);
		}
		else if ((*b)->value == start)
		{
			if (pa_ra_set(a, b, info, 1))
				return (ERROR);
			if (command_loop(a, b, info, 2, PA))
				return (ERROR);
			if (command_loop(a, b, info, 2, RA))
				return (ERROR);
		}
		else if ((*b)->value == start + 1)
			return (b_qs2(a, b, info, start));
		else
			return (b_qs3(a, b, info, start));
	}
	else
		return (b_qs4(a, b, info, start, end));
	return (SUCCESS);
}