/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:39:36 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 21:16:11 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_6_util(t_info **info, int len, int loc, int min)
{
	while (len > 3)
	{
		while (min != (*info)->a->value)
		{
			if (loc <= len / 2)
			{
				if (add_ans_ra(info))
					return (ERROR);
			}
			else
			{
				if (add_ans_rra(info))
					return (ERROR);
			}
			loc++;
		}
		if (add_ans_pb(info))
			return (ERROR);
		len--;
		min = stackmin(&((*info)->a), &loc, len);
	}
	return (SUCCESS);
}

int	sort_6(t_info **info)
{
	int		len;
	int		loc;
	long	min;

	len = stacklen((*info)->a);
	loc = 0;
	min = stackmin(&((*info)->a), &loc, len);
	if (sort_6_util(info, len, loc, min))
		return (ERROR);
	if (sort_3(info))
		return (ERROR);
	while (stacklen((*info)->b) > 0)
	{
		if (add_ans_pa(info))
			return (ERROR);
	}
	return (SUCCESS);
}
