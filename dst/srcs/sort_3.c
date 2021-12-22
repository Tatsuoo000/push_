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

void	sort_3(s_info **info)
{
	long	first;
	long	second;
	long	third;

	while((*info)->a->value != DUMMY)
	{
		(*info)->a = (*info)->a->next;
	}
	first = (*info)->a->next->value;
	second = (*info)->a->next->next->value;
	third = (*info)->a->next->next->next->value;
	if (first > second && first < third)
		add_ans_sa(info);
	if (second > third && second < first)
	{
		add_ans_sa(info);
		add_ans_rra(info);
	}
	if (third > second && third < first)
		add_ans_ra(info);
	if (third > first && third < second)
	{
		add_ans_sa(info);
		add_ans_ra(info);
	}
	if (first > third && first < second)
		add_ans_rra(info);
}
