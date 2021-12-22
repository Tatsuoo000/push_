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

int pa_or_ra_min(s_info **info, int *start)
{
	char	cmd;

	if ((*info)->a->value == (*info)->min_value)
	{
		cmd = RA;
		++(*start);
		++(*info)->min_value;
	}
	else
		cmd = PB;
	command_exec(info, cmd);
	return (SUCCESS);
}

int	sa_min(s_info **info)
{
	if ((*info)->a->value == (*info)->min_value + 1 && \
		(*info)->a->next->value == (*info)->min_value)
		if (command_loop(info, 1, SA))
			return (ERROR);
	return (SUCCESS);
}
