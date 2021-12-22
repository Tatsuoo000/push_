/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:22:38 by tkano             #+#    #+#             */
/*   Updated: 2021/12/15 20:22:38 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap_push3(s_stack **a, s_stack **b, s_info **info)
{
	if (command_loop(a, b, info, 1, PB))
		return (ERROR);
	if (command_loop(a, b, info, 1, SA))
		return (ERROR);
	if (command_loop(a, b, info, 2, RA))
		return (ERROR);
	if (pa_ra_set(a, b, info, 1))
		return (ERROR);
	(*info)->min_value += 3;
	return (SUCCESS);
}

int	swap_push2(s_stack **a, s_stack **b, s_info **info)
{
	if ((*info)->min_value == (*a)->next->value && \
		(*info)->min_value + 1 == (*a)->next->next->value)
	{
		if (command_loop(a, b, info, 1, SA))
			return (ERROR);
		if (command_loop(a, b, info, 1, RA))
			return (ERROR);
		if (command_loop(a, b, info, 1, SA))
			return (ERROR);
		if (command_loop(a, b, info, 2, RA))
			return (ERROR);
		(*info)->min_value += 3;
	}
	else if ((*info)->min_value + 1 == (*a)->next->value && \
			(*info)->min_value == (*a)->next->next->value)
		return (swap_push3(a, b, info));
	return (SUCCESS);
}

int	swap_push(s_stack **a, s_stack **b, s_info **info)
{
	if ((*info)->min_value + 1 == (*a)->value && \
		(*info)->min_value + 2 == (*a)->next->value && \
		(*info)->min_value == (*a)->next->next->value)
	{
		if (command_loop(a, b, info, 1, PB))
			return (ERROR);
		if (command_loop (a, b, info, 1, SA))
			return (ERROR);
		if (command_loop(a, b, info, 1, RA))
			return (ERROR);
		if (command_loop(a, b, info, 1, PA))
			return (ERROR);
		if (command_loop(a, b, info, 2, RA))
			return (ERROR);
		(*info)->min_value += 3;
	}
	else if ((*info)->min_value + 2 == (*a)->value)
		return (swap_push(a, b, info));
	return (SUCCESS);
}
