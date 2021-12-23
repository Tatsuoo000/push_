/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:42:36 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:31:08 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_3_util(t_info **info, long first, long second, long third)
{
	if (first > second && first < third)
		if (add_ans_sa(info))
			return (ERROR);
	if (second > third && second < first)
	{
		if (add_ans_sa(info))
			return (ERROR);
		if (add_ans_rra(info))
			return (ERROR);
	}
	if (third > second && third < first)
		if (add_ans_ra(info))
			return (ERROR);
	if (third > first && third < second)
	{
		if (add_ans_sa(info))
			return (ERROR);
		if (add_ans_ra(info))
			return (ERROR);
	}
	if (first > third && first < second)
		if (add_ans_rra(info))
			return (ERROR);
	return (SUCCESS);
}

int	sort_3(t_info **info)
{
	long	first;
	long	second;
	long	third;

	while ((*info)->a->value != DUMMY)
	{
		(*info)->a = (*info)->a->next;
	}
	first = (*info)->a->next->value;
	second = (*info)->a->next->next->value;
	third = (*info)->a->next->next->next->value;
	if (sort_3_util(info, first, second, third))
		return (ERROR);
	return (SUCCESS);
}
