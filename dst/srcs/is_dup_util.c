/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:46 by tkano             #+#    #+#             */
/*   Updated: 2021/12/08 18:07:46 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	int_cpy(int *p, const int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		++i;
	}
}

void	replacement_to_index(s_stack *a, int *array)
{
	int	i;

	while (a->value != DUMMY)
	{
		i = 0;
		while (array[i] != a->value)
			++i;
		a->value = i;
		a = a->next;
	}
}
