/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:45:42 by tkano             #+#    #+#             */
/*   Updated: 2021/12/23 12:35:38 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	b_qs4(t_info **info, int start, int end)
{
	if (end - start == 2)
	{
		(*info)->min_value += 2;
		if ((*info)->b->value == start)
		{
			if (pa_ra_set(info, 2))
				return (ERROR);
		}
		else
		{
			if (command_loop(info, 2, PA))
				return (ERROR);
			if (command_loop(info, 2, RA))
				return (ERROR);
		}
	}
	else
	{
		(*info)->min_value += 1;
		if (pa_ra_set(info, 1))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_qs3(t_info **info, int start)
{
	if ((*info)->b->next->value == start)
	{
		if (command_loop(info, 2, PA))
			return (ERROR);
		if (command_loop(info, 1, RA))
			return (ERROR);
		if (command_loop(info, 1, PA))
			return (ERROR);
		if (command_loop(info, 2, RA))
			return (ERROR);
	}
	else
	{
		if (command_loop(info, 3, PA))
			return (ERROR);
		if (command_loop(info, 3, RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_qs2(t_info **info, int start)
{
	if ((*info)->b->next->value == start)
	{
		if (command_loop(info, 2, PA))
			return (ERROR);
		if (command_loop(info, 2, RA))
			return (ERROR);
		if (pa_ra_set(info, 1))
			return (ERROR);
	}
	else
	{
		if (command_loop(info, 1, RB))
			return (ERROR);
		if (command_loop(info, 2, PA))
			return (ERROR);
		if (command_loop(info, 1, RA))
			return (ERROR);
		if (command_loop(info, 1, PA))
			return (ERROR);
		if (command_loop(info, 2, RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	b_quicksort(t_info **info, int start, int end)
{
	if (end - start == 3)
	{
		(*info)->min_value += 3;
		if ((*info)->b->value == start && (*info)->b->next->value == start + 1)
		{
			if (pa_ra_set(info, 3))
				return (ERROR);
		}
		else if ((*info)->b->value == start)
		{
			if (pa_ra_set(info, 1))
				return (ERROR);
			if (command_loop(info, 2, PA))
				return (ERROR);
			if (command_loop(info, 2, RA))
				return (ERROR);
		}
		else if ((*info)->b->value == start + 1)
			return (b_qs2(info, start));
		else
			return (b_qs3(info, start));
	}
	else
		return (b_qs4(info, start, end));
	return (SUCCESS);
}
