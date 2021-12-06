/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmeidian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:33:05 by tkano             #+#    #+#             */
/*   Updated: 2021/10/07 18:28:08 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	median_rec(s_stack *v, long min)
{
	long	ret;
	//int		i;

	//i = 1;
	while (v->prev->value != DUMMY)
	{
		v = v->next;
	}
	ret = __INT_MAX__;
	while(v->value != DUMMY)
	{
		if (min < v->value && ret > v->value)
		{
			ret = v->value;
			//printf("median: %ld\n", ret);
		}
		v = v->next;
	}
	return (ret);
}

long	stackmedian(s_stack **v)
{
	long	ret;
	int		len;
	int		i;
	int		loc;

	len = stacklen(*v);
	i = 0;
	loc = 0;
	ret = stackmin(v, &loc, len);
	while (i < len / 2)
	{
		ret = median_rec(*v, ret);
		i++;
	}
	while ((*v)->prev->value != DUMMY)
	{
		(*v) = (*v)->next;
	}
	//printf("median: %ld\n", ret);
	return (ret);
}