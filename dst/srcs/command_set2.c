/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_set2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:46:24 by tkano             #+#    #+#             */
/*   Updated: 2021/12/15 20:46:24 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int pa_or_ra_min(s_stack **a, s_stack **b, s_info **info, int *start)
{
	char	cmd;

	if ((*a)->value == (*info)->min_value)
	{
		cmd = RA;
		++(*start);
		++(*info)->min_value;
	}
	else
		cmd = PB;
	command_exec(a, b, info, cmd);
	return (SUCCESS);
}

int	sa_min(s_stack **a, s_stack **b, s_info **info)
{
	if ((*a)->value == (*info)->min_value + 1 && \
		(*a)->next->value == (*info)->min_value)
		if (command_loop(a, b, info, 1, SA))
			return (ERROR);
	return (SUCCESS);
}
