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

int	quick_sort(t_info **info, int start, int end)
{
	int	middle;

	if (start >= end)
		return (SUCCESS);
	if (end - start <= 3)
	{
		if (b_quicksort(info, start, end))
			return (ERROR);
		return (SUCCESS);
	}
	middle = (end - start - 1) / 2 + 1 + start;
	if (b_half_set(info, &start, middle, end))
		return (ERROR);
	if (quick_sort(info, start, middle))
		return (ERROR);
	if (middle < (*info)->min_value)
		middle = (*info)->min_value;
	if (quicksort_second(info, &middle, end))
		return (ERROR);
	if (quick_sort(info, middle, end))
		return (ERROR);
	return (SUCCESS);
}

int	sort_100(t_info **info)
{
	int	median;

	median = ((*info)->size -1) / 2 + 1;
	if (first_half_set(info, median))
		return (ERROR);
	while ((*info)->min_value < median)
	{
		if (quick_sort(info, (*info)->min_value, median))
			return (ERROR);
	}
	median = (*info)->min_value;
	if (quicksort_second(info, &median, (*info)->size))
		return (ERROR);
	while ((*info)->min_value < (*info)->size)
		if (quick_sort(info, (*info)->min_value, (*info)->size))
			return (ERROR);
	return (SUCCESS);
}
