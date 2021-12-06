/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:08:02 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:13:25 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_sb(s_stack **b)
{
	long	tmp;

	while ((*b)->prev->value != DUMMY)
	{
		*b = (*b)->next;
	}
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
}
