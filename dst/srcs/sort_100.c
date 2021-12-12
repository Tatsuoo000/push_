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

int	quick_sort(s_stack **a, s_stack **b, s_info **info)
{
	int	median;

	if ((*info)->min_value >= (*info)->median)
		return (SUCCESS);
	if ((*info)->median - (*info)->min_value <= 3)
	{
		if (b_quicksort(a, b, info))
			return (ERROR);
		return (SUCCESS);
	}
	*/
	middle = (end - start - 1) / 2 + 1 + start;
	if (qs_first_half(set, &start, end, middle))
		return (ERROR);
	if (qs(set, start, middle))
		return (ERROR);
	if (middle < set->min_value)
		middle = set->min_value;
	if (qs_second_half(set, end, &middle))
		return (ERROR);
	if (qs(set, middle, end))
		return (ERROR);
	*/
	return (SUCCESS);
}

int		sort_100(s_stack **a, s_stack **b, s_info **info)
{
	(*info)->median = ((*info)->size -1) / 2 + 1;
	if (first_half_set(a, b, info))
	 	return (ERROR);
	while ((*info)->min_value < (*info)->median)
		if (quick_sort(a, b,info))
			return (ERROR);
	(*info)->median = (*info)->min_value;
	//printf("start: %ld\n", (*a)->value);
	//quick_sort(a, b, info);
	put_stack(*a);
	put_stack(*b);
	return (SUCCESS);

}