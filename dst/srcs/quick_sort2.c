/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:20:34 by tkano             #+#    #+#             */
/*   Updated: 2021/12/15 19:20:34 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap_flag(t_ft_stack **a, t_info **info)
{
	if ((*info)->min_value + 1 == (*a)->value && \
		(*info)->min_value + 2 == (*a)->next->value && \
		(*info)->min_value == (*a)->next->next->value)
		return (1);
	if ((*info)->min_value + 2 == (*a)->value && \
		(*info)->min_value == (*a)->next->value && \
		(*info)->min_value + 1 == (*a)->next->next->value)
		return (1);
	if ((*info)->min_value + 2 == (*a)->value && \
		(*info)->min_value + 1 == (*a)->next->value && \
		(*info)->min_value == (*a)->next->next->value)
		return (1);
	return (0);
}

int	quicksort_second(t_info **info, int *middle, int end)
{
	int	i;

	i = *middle;
	while (i < end)
	{
		if (swap_flag(&((*info)->a), info))
		{
			if (swap_push(info))
				return (ERROR);
			*middle += 3;
			i += 3;
		}
		else
		{
			if (sa_min(info))
				return (ERROR);
			if (pa_or_ra_min(info, middle))
				return (ERROR);
			++i;
		}
	}
	return (SUCCESS);
}
