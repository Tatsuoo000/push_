/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:05:33 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 19:56:55 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_rra(s_stack **a)
{
	long	tmp;

	while ((*a)->next->value != DUMMY)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = DUMMY;
	(*a)->next->value = tmp;
}

void	ft_put_rra(void)
{
	write(1, "rra\n", 4);
}
