/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:28:18 by tkano             #+#    #+#             */
/*   Updated: 2021/10/04 14:58:19 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_2(s_stack **a)
{
	if ((*a)->next->value > (*a)->next->next->value)
	{
		do_sa(a);
		ft_put_sa();
	}
}
