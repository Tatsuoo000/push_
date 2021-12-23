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

long	pop(t_ft_stack **v)
{
	long		ret;
	t_ft_stack	*tmp;

	while ((*v)->prev->value != DUMMY)
	{
		*v = (*v)->next;
	}
	ret = (*v)->value;
	tmp = (*v)->next;
	(*v)->prev->next = (*v)->next;
	(*v)->next->prev = (*v)->prev;
	*v = tmp;
	return (ret);
}

int	push(t_ft_stack **v, long num)
{
	t_ft_stack	*new;

	new = malloc(sizeof(t_ft_stack));
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

int	do_pb(t_ft_stack **a, t_ft_stack **b)
{
	long	tmp;

	tmp = pop(a);
	if (push(b, tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	add_ans_pb(t_info **info)
{
	if (do_pb(&((*info)->a), &((*info)->b)))
		return (ERROR);
	if (add_stack(&((*info)->ans), PB))
		return (ERROR);
	return (SUCCESS);
}
