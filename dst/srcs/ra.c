/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:45:11 by tkano             #+#    #+#             */
/*   Updated: 2021/08/03 12:00:50 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_ra(s_stack **a)
{
	int	tmp;

	while ((*a)->prev->value != 0)
	{
		*a = (*a)->next;
	}
	tmp = (*a)->value;
	(*a)->value = 0;
	(*a)->prev->value = tmp;
}
