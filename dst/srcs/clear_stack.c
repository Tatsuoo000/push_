/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:28:32 by tkano             #+#    #+#             */
/*   Updated: 2021/07/14 22:15:41 by tkano            ###   ########.fr       */
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
	printf("1st: %d\n", (*v)->value);
	while ((*v)->value != 0)
	{
		tmp = (*v)->next;
		*v = NULL;
		free(*v);
		*v = tmp;
		printf("clear: %p\n", *v);
	}
	*v = NULL;
	free(*v);
}
