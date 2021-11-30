/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:09:56 by tkano             #+#    #+#             */
/*   Updated: 2021/08/05 11:09:56 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	do_pa(s_stack **a, s_stack **b)
{
	long	tmp;

	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	tmp = pop(b);
	//printf("pb: %p, value: %d\n", *a, (*a)->value);
	if (push(a, tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	ft_put_pa(void)
{
	write(1, "pa\n", 3);
}
