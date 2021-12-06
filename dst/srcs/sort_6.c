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

int		sort_6(s_stack **a, s_stack **b)
{
	int		len;
	int		loc;
	long	min;

	len = stacklen(*a);
	loc = 0;
	min = stackmin(a, &loc, len);
	while (len > 3)
	{
		while (min != (*a)->next->value)
		{
			if (loc < len / 2)
			{
				do_ra(a);
				ft_put_ra();
			}
			else
			{
				do_rra(a);
				ft_put_rra();
			}
			loc++;
			//printf("num: %ld, loc: %d, start: %ld\n", min, loc, (*a)->value);
		}
		//printf("check5\n");
		do_pb(a, b);
		ft_put_pb();
		len--;
		min = stackmin(a, &loc, len);
	}
	sort_3(a);
	while (stacklen(*b) > 0)
	{
		do_pa(a, b);
		ft_put_pa();
	}
	return (0);
}
