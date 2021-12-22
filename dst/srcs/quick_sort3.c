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

int	swap_push3(s_info **info)
{
	if (command_loop(info, 1, PB))
		return (ERROR);
	if (command_loop(info, 1, SA))
		return (ERROR);
	if (command_loop(info, 2, RA))
		return (ERROR);
	if (pa_ra_set(info, 1))
		return (ERROR);
	(*info)->min_value += 3;
	return (SUCCESS);
}

int	swap_push2(s_info **info)
{
	if ((*info)->min_value == (*info)->a->next->value && \
		(*info)->min_value + 1 == (*info)->a->next->next->value)
	{
		if (command_loop(info, 1, SA))
			return (ERROR);
		if (command_loop(info, 1, RA))
			return (ERROR);
		if (command_loop(info, 1, SA))
			return (ERROR);
		if (command_loop(info, 2, RA))
			return (ERROR);
		(*info)->min_value += 3;
	}
	else if ((*info)->min_value + 1 == (*info)->a->next->value && \
			(*info)->min_value == (*info)->a->next->next->value)
		return (swap_push3(info));
	return (SUCCESS);
}

int	swap_push(s_info **info)
{
	if ((*info)->min_value + 1 == (*info)->a->value && \
		(*info)->min_value + 2 == (*info)->a->next->value && \
		(*info)->min_value == (*info)->a->next->next->value)
	{
		if (command_loop(info, 1, PB))
			return (ERROR);
		if (command_loop (info, 1, SA))
			return (ERROR);
		if (command_loop(info, 1, RA))
			return (ERROR);
		if (command_loop(info, 1, PA))
			return (ERROR);
		if (command_loop(info, 2, RA))
			return (ERROR);
		(*info)->min_value += 3;
	}
	else if ((*info)->min_value + 2 == (*info)->a->value)
		return (swap_push2(info));
	return (SUCCESS);
}
