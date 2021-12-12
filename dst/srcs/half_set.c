/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:58:57 by tkano             #+#    #+#             */
/*   Updated: 2021/12/11 00:11:24 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int first_half_set(s_stack **a, s_stack **b, s_info **info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (*info)->size && j < (*info)->median)
	{
		//printf("size: %ld, median: %ld\n", (*info)->size, (*info)->median);
		if ((*a)->value >= (*info)->median)
		{
			if (add_ans_ra(a, info))
				return (ERROR);
		}
		else
		{
			++j;
			if (add_ans_pb(a, b, info))
				return (ERROR);
		}
		++i;
	}
	return (SUCCESS);
}
