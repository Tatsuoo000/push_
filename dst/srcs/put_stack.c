/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:56:16 by tkano             #+#    #+#             */
/*   Updated: 2021/07/09 13:56:16 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	put_stack(s_stack *v)
{
	printf("=======stack=====\n");
	while (v->prev->value != 0)
	{
		v = v->next;
	}
	while(v->value != 0)
	{
		ft_putnbr_fd(v->value, 1);
		write(1, "\n", 1);
		v = v->next;
	}
}