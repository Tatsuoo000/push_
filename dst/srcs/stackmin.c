/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:08:58 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 21:14:23 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	stackmin(t_ft_stack **a, int *loc, int len)
{
	long	min;
	int		i;

	i = 1;
	while ((*a)->prev->value != DUMMY)
	{
		*a = (*a)->next;
	}
	min = (*a)->value;
	while (i != len)
	{
		*a = (*a)->next;
		if (min > (*a)->value)
		{
			min = (*a)->value;
			*loc = ++i;
		}
		else
			i++;
	}
	while ((*a)->prev->value != DUMMY)
	{
		*a = (*a)->prev;
	}
	return (min);
}
