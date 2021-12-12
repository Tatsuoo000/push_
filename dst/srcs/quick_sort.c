/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:45:42 by tkano             #+#    #+#             */
/*   Updated: 2021/12/11 12:37:39 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	b_quicksort(s_stack **a, s_stack **b, s_info **info)
{
	int start;

	start = (*info)->min_value;
	if ((*info)->median - start == 3)
	{
		(*info)->min_value += 3;
		if ((*b)->value == start && (*b)->next->value == start + 1)
		{
			if (pa_ra_set(a, b, info, 3))
				return (ERROR);
		}
		else if ((*b)->value == start)
		{
			if (pa_ra_set(a, b, info, 1))
				return (ERROR);
			if (command_loop(set, 2, COMMAND_PA))
				return (ERROR);
			if (command_loop(set, 2, COMMAND_RA))
				return (ERROR);
		}
		else if (*(set->list2->v) == start + 1)
			return (bfs_qs2(set, start));
		else
			return (bfs_qs3(set, start));
	}
	}
}