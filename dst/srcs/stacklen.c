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

int	stacklen(t_ft_stack *v)
{
	int	len;

	len = 0;
	while (v->prev->value != DUMMY)
	{
		v = v->next;
	}
	while (v->value != DUMMY)
	{
		len++;
		v = v->next;
	}
	return (len);
}
