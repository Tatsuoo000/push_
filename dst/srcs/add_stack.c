/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:01:56 by tkano             #+#    #+#             */
/*   Updated: 2021/07/08 20:46:47 by tkano            ###   ########.fr       */
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
	new->next = *v;
	(*v)->prev = new;
	while ((*v)->next->value != 0)
	{
		*v = (*v)->next;
	}
	new->prev = *v;
	(*v)->next = new;
	return (SUCCESS);
}
