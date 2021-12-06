/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:22:20 by tkano             #+#    #+#             */
/*   Updated: 2021/10/11 22:49:53 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		quick_sort_b(s_stack **a, s_stack **b, long median)
{
	if (stacklen(*b) < 7)
	{
		sort_6(b, a);
		return (SUCCESS);
	}
	median = stackmedian(b);
	while ((*b)->value != DUMMY)
	{
		if ((*b)->value < median)
		{
			do_pa(a, b);
			ft_put_pa();
		}
		(*b) = (*b)->next;
	}
	quick_sort_b(a, b, median);
	return (ERROR);
}

int		quick_sort(s_stack **a, s_stack **b, long median)
{
	int	i;

	i = 0;
	while ((*a)->value != DUMMY)
	{
		if ((*a)->value <= median)
		{
			do_pb(a, b);
			ft_put_pb();
		}
		(*a) = (*a)->next;
		i++;
	}
	quick_sort_b(a, b, median);
	return (SUCCESS);
}

int		sort_100(s_stack **a, s_stack **b)
{
	long	median;

	median = stackmedian(a);
	//printf("start: %ld\n", (*a)->value);
	quick_sort(a, b, median);
	put_stack(*b);
	return (SUCCESS);

}