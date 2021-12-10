/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:09:56 by tkano             #+#    #+#             */
/*   Updated: 2021/08/05 11:09:56 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	do_pa(s_stack **a, s_stack **b)
{
	long	tmp;

	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	tmp = pop(b);
	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	if (push(a, tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_pa(s_stack **a, s_stack **b, s_info **info)
{
	if (do_pa(a, b))
		return (ERROR);
	if (add_stack(&((*info)->ans), PA))
		return (ERROR);
	return (SUCCESS);
}
