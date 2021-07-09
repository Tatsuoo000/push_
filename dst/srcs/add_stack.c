/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:01:56 by tkano             #+#    #+#             */
/*   Updated: 2021/07/09 15:36:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	add_stack(s_stack **v, int num)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (ERROR);
	new->value = num;
	while ((*v)->next->value != 0)
	{
		*v = (*v)->next;
	}
	new->prev = *v;
	(*v)->next = new;
	while ((*v)->value != 0)
	{
		*v = (*v)->prev;
	}
	(*v)->prev = new;
	new->next = *v;
	return (SUCCESS);
}
