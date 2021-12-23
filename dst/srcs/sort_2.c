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

int	sort_2(t_info **info)
{
	if ((*info)->a->next->value > (*info)->a->next->next->value)
		if (add_ans_sa(info))
			return (ERROR);
	return (SUCCESS);
}
