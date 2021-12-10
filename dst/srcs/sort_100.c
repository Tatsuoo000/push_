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

/***
int		quick_sort(s_stack **a, s_stack **b, s_info **info)
{
	int	middle;

	middle = ((*info)->size -1) / 2 + 1;
	//if (first_half_set(a, b, info, middle))
	 	//return (ERROR);
	return (SUCCESS);
}
***/

int		sort_100(s_stack **a, s_stack **b, s_info **info)
{
	(*info)->median = ((*info)->size -1) / 2 + 1;
	//if (first_half_set(a, b, info))
	 	//return (ERROR);
	//printf("start: %ld\n", (*a)->value);
	//quick_sort(a, b, info);
	put_stack(*a);
	put_stack(*b);
	return (SUCCESS);

}