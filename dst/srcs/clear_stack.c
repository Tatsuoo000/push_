/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:28:32 by tkano             #+#    #+#             */
/*   Updated: 2021/08/05 11:08:01 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	clear_stack(s_stack **v)
{
	s_stack	*tmp;

	while ((*v)->prev->value != 0)
	{
		*v = (*v)->next;
	}
	//printf("1st: %d\n", (*v)->value);
	while ((*v)->value != 0)
	{
		tmp = *v;
		(*v) = (*v)->next;
		free(tmp);
		tmp = NULL;
		//printf("clear: %p\n", tmp);
		//printf("clear: %p\n", *v);
	}
	free(*v);
	*v = NULL;
}
