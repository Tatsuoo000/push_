/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:51:28 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 21:16:50 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stacklen(s_stack *v)
{
	int	len;

	len = 0;
	//printf("check1\n");
	while (v->prev->value != DUMMY)
	{
		v = v->next;
	}
	while(v->value != DUMMY)
	{
		len++;
		v = v->next;
	}
	//printf("check2, len: %d\n", len);
	return (len);
}
