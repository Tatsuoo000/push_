/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:28:32 by tkano             #+#    #+#             */
/*   Updated: 2021/10/05 22:31:03 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	clear_stack(t_ft_stack **v)
{
	t_ft_stack	*tmp;

	if (*v == NULL)
		return ;
	while ((*v)->prev->value != DUMMY)
	{
		*v = (*v)->next;
	}
	while ((*v)->value != DUMMY)
	{
		tmp = *v;
		(*v) = (*v)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*v);
	*v = NULL;
}
