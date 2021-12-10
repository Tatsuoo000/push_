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

void	sort_3(s_stack **a, s_info **info)
{
	long	first;
	long	second;
	long	third;

	while((*a)->value != DUMMY)
	{
		*a = (*a)->next;
	}
	first = (*a)->next->value;
	second = (*a)->next->next->value;
	third = (*a)->next->next->next->value;
	if (first > second && first < third)
		add_ans_sa(a, info);
	if (second > third && second < first)
	{
		add_ans_sa(a, info);
		add_ans_rra(a, info);
	}
	if (third > second && third < first)
		add_ans_ra(a, info);
	if (third > first && third < second)
	{
		add_ans_sa(a, info);
		add_ans_ra(a, info);
	}
	if (first > third && first < second)
		add_ans_rra(a, info);
}
