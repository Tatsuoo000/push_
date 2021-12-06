/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:09:32 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:31:17 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	init_stack(s_stack **v)
{
	*v = malloc(sizeof(s_stack));
	if (!v)
		return (ERROR);
	(*v)->value = DUMMY;
	(*v)->prev = *v;
	(*v)->next = *v;
	return (SUCCESS);
}

int	set_stack(s_stack **a, s_stack **b, int argc, char **argv)
{
	int		i;

	if (init_stack(a) == ERROR)
		return (ERROR);
	if (init_stack(b) == ERROR)
		return (ERROR);
	i = 1;
	//printf("v_sentinental: %p\n", *a);
	while (i < argc)
	{
		if (add_stack(a, ft_atoi(argv[i])) == ERROR)
			return (ERROR);
		//printf("v->now: %d\n", (*a)->next->value);
		i++;
	}
	//printf("v->next: %d\n", (*a)->next->value);
	return (SUCCESS);
}
