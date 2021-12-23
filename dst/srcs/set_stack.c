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

int	init_stack(t_ft_stack **v)
{
	*v = malloc(sizeof(t_ft_stack));
	if (!v)
		return (ERROR);
	(*v)->value = DUMMY;
	(*v)->prev = *v;
	(*v)->next = *v;
	return (SUCCESS);
}

int	set_stack(t_ft_stack **a, t_ft_stack **b, int argc, char **argv)
{
	int		i;

	if (init_stack(a) == ERROR)
		return (ERROR);
	if (init_stack(b) == ERROR)
		return (ERROR);
	i = 1;
	while (i < argc)
	{
		if (add_stack(a, ft_atoi(argv[i])) == ERROR)
			return (ERROR);
		i++;
	}
	while ((*a)->prev->value != DUMMY)
	{
		(*a) = (*a)->next;
	}
	return (SUCCESS);
}
