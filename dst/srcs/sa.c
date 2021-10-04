/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:08:02 by tkano             #+#    #+#             */
/*   Updated: 2021/10/04 14:58:06 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_sa(s_stack **a)
{
	int	tmp;

	while ((*a)->prev->value != 0)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
}

void	ft_put_sa(void)
{
	write(1, "sa\n", 3);
}
