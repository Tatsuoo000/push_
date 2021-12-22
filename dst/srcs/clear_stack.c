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

void	clear_stack(s_stack **v)
{
	s_stack	*tmp;

	if (*v == NULL)
		return ;
	while ((*v)->prev->value != DUMMY)
	{
		*v = (*v)->next;
	}
	//printf("1st: %d\n", (*v)->value);
	while ((*v)->value != DUMMY)
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
