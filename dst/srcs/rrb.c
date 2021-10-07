/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:44:44 by tkano             #+#    #+#             */
/*   Updated: 2021/08/05 11:44:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_rrb(s_stack **b)
{
	long	tmp;

	while ((*b)->next->value != DUMMY)
	{
		*b = (*b)->next;
	}
	tmp = (*b)->value;
	(*b)->value = DUMMY;
	(*b)->next->value = tmp;
}
