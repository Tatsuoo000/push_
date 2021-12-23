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

int	do_pa(t_ft_stack **a, t_ft_stack **b)
{
	long	tmp;

	tmp = pop(b);
	if (push(a, tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_pa(t_info **info)
{
	if (do_pa(&((*info)->a), &((*info)->b)))
		return (ERROR);
	if (add_stack(&((*info)->ans), PA))
		return (ERROR);
	return (SUCCESS);
}
