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

int		sort_6(s_stack **a, s_stack **b, s_info **info)
{
	int		len;
	int		loc;
	long	min;

	len = stacklen(*a);
	loc = 0;
	min = stackmin(a, &loc, len);
	while (len > 3)
	{
		//printf("num: %ld, loc: %d, start: %ld, len: %d\n", min, loc, (*a)->value, len);
		while (min != (*a)->value)
		{
			if (loc < len / 2)
				add_ans_ra(a, info);
			else
				add_ans_rra(a, info);
			loc++;
			//printf("num: %ld, loc: %d, start: %ld\n", min, loc, (*a)->value);
		}
		//printf("check5\n");
		add_ans_pb(a, b, info);
		len--;
		min = stackmin(a, &loc, len);
	}
	sort_3(a, info);
	while (stacklen(*b) > 0)
		add_ans_pa(a, b, info);
	return (0);
}
