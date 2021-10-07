/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:45:11 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 20:00:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_ra(s_stack **a)
{
	long	tmp;

	while ((*a)->prev->value != DUMMY)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = DUMMY;
	(*a)->prev->value = tmp;
}

void	ft_put_ra(void)
{
	write(1, "ra\n", 3);
}
