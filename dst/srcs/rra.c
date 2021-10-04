/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:05:33 by tkano             #+#    #+#             */
/*   Updated: 2021/10/04 15:13:30 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_rra(s_stack **a)
{
	int	tmp;

	while ((*a)->next->value != 0)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = 0;
	(*a)->next->value = tmp;
}

void	ft_put_rra(void)
{
	write(1, "rra\n", 4);
}
