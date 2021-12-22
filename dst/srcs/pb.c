/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:46:27 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 21:13:37 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	pop(s_stack **v)
{
	long	ret;
	s_stack	*tmp;

	while ((*v)->prev->value != DUMMY)
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
	//free(*v);
	//*v = NULL;
	*v = tmp;
	return (ret);
}

int	push(s_stack **v, long num)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (ERROR);
	new->value = num;
	while ((*v)->prev->value != DUMMY)
	{
		*v = (*v)->next;
	}
	new->prev = (*v)->prev;
	new->next = (*v);
	(*v)->prev->next = new;
	(*v)->prev = new;
	*v = (*v)->prev;
	return (SUCCESS);
}

int	do_pb(s_stack **a, s_stack **b)
{
	long	tmp;

	//printf("pb: %p, value: %ld\n", *a, (*a)->value);
	tmp = pop(a);
	//printf("pb: %p, value: %ld\n", *a, (*a)->value);
	if (push(b, tmp) == ERROR)
		return (ERROR);
	//printf("pb: %p, value: %ld\n", *a, (*a)->value);
	return (SUCCESS);
}

int	add_ans_pb(s_info **info)
{
	if (do_pb(&((*info)->a), &((*info)->b)))
		return (ERROR);
	if (add_stack(&((*info)->ans), PB))
		return (ERROR);
	return (SUCCESS);
}
