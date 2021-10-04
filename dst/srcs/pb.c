/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:46:27 by tkano             #+#    #+#             */
/*   Updated: 2021/10/04 20:22:46 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pop(s_stack **v)
{
	int		ret;
	s_stack	*tmp;

	while ((*v)->prev->value != 0)
	{
		*v = (*v)->next;
	}
	ret = (*v)->value;
	tmp = (*v)->next;
	//printf("clear: %p, value: %d\n", *v, (*v)->value);
	//printf("clear: %p, value: %d\n", (*v)->prev->next, (*v)->prev->next->value);
	(*v)->prev->next = (*v)->next;
	//printf("clear: %p\n", (*v)->prev);
	//printf("prev: %p, value: %d\n", (*v)->next->prev, (*v)->next->prev->value);
	(*v)->next->prev = (*v)->prev;
	free(*v);
	*v = NULL;
	*v = tmp;
	return (ret);
}

int	push(s_stack **v, int num)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (ERROR);
	new->value = num;
	while ((*v)->prev->value != 0)
	{
		*v = (*v)->next;
	}
	new->prev = (*v)->prev;
	new->next = (*v);
	(*v)->prev->next = new;
	(*v)->prev = new;
	return (SUCCESS);
}

int	do_pb(s_stack **a, s_stack **b)
{
	int	tmp;

	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	tmp = pop(a);
	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	if (push(b, tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	ft_put_pb(void)
{
	write(1, "pb\n", 3);
}
