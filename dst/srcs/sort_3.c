/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:42:36 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:31:08 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(s_stack **a)
{
	long	first;
	long	second;
	long	third;

	while((*a)->value != DUMMY)
	{
		*a = (*a)->next;
	}
	first = (*a)->next->value;
	second = (*a)->next->next->value;
	third = (*a)->next->next->next->value;
	if (first > second && first < third)
	{
		do_sa(a);
		ft_put_sa();
	}
	if (second > third && second < first)
	{
		do_sa(a);
		ft_put_sa();
		do_rra(a);
		ft_put_rra();
	}
	if (third > second && third < first)
	{
		do_ra(a);
		ft_put_ra();
	}
	if (third > first && third < second)
	{
		do_sa(a);
		ft_put_sa();
		do_ra(a);
		ft_put_ra();
	}
	if (first > third && first < second)
	{
		do_rra(a);
		ft_put_rra();
	}
}
