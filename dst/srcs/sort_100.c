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

int	quick_sort(s_stack **a, s_stack **b, s_info **info, int start, int end)
{
	int	middle;

	if (start >= end)
		return (SUCCESS);
	if (end - start <= 3)
	{
		if (b_quicksort(a, b, info, start, end))
			return (ERROR);
		return (SUCCESS);
	}
	middle = (end - start - 1) / 2 + 1 + start;
	//printf("quick_sort: start: %d, middle: %d, end %d\n", start,  middle, end);
	//put_stack(*a);
	if (b_half_set(a, b, info, &start, middle, end))
		return (ERROR);
	if (quick_sort(a, b, info, start, middle))
		return (ERROR);
	if (middle < (*info)->min_value)
		middle = (*info)->min_value;
	//printf("quick_sort: start: %d, middle: %d, end %d\n", start,  middle, end);
	if (quicksort_second(a, b, info, &middle, end))
		return (ERROR);
	//put_stack(*a);
	if (quick_sort(a, b, info, middle, end))
		return (ERROR);
	return (SUCCESS);
}

int		sort_100(s_stack **a, s_stack **b, s_info **info)
{
	int	median;

	median = ((*info)->size -1) / 2 + 1;
	if (first_half_set(a, b, info, median))
	 	return (ERROR);
	while ((*info)->min_value < median)
	{
		//printf("quick_sort: start: %ld, end %d\n", (*info)->min_value, median);
		if (quick_sort(a, b,info, (*info)->min_value, median))
			return (ERROR);
	}
	median = (*info)->min_value;
	//put_stack(*a);
	//put_stack(*b);
	//printf("before later half median: %d, min_value: %ld, end: %ld\n", median, (*info)->min_value, (*info)->size);
	if (quicksort_second(a, b, info, &median, (*info)->size))
		return (ERROR);
	while ((*info)->min_value < (*info)->size)
		if (quick_sort(a, b, info, (*info)->min_value, (*info)->size))
			return (ERROR);
	//printf("start: %ld\n", (*a)->value);
	//quick_sort(a, b, info);
	return (SUCCESS);

}