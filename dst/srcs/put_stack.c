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
	while (v->prev->value != DUMMY)
	{
		v = v->next;
	}
	while(v->value != DUMMY)
	{
		ft_putnbr_fd(v->value, 1);
		write(1, "\n", 1);
		v = v->next;
	}
}

void	put_selected_command(s_stack *cmd)
{
		if (cmd->value == PA)
			ft_putstr_fd("PA", 1);
		if (cmd->value == PB)
			ft_putstr_fd("PB", 1);
		if (cmd->value == SA)
			ft_putstr_fd("SA", 1);
		if (cmd->value == SB)
			ft_putstr_fd("SB", 1);
		if (cmd->value == SS)
			ft_putstr_fd("SS", 1);
		if (cmd->value == RA)
			ft_putstr_fd("RA", 1);
		if (cmd->value == RB)
			ft_putstr_fd("RB", 1);
		if (cmd->value == RR)
			ft_putstr_fd("RR", 1);
		if (cmd->value == RRA)
			ft_putstr_fd("RRA", 1);
		if (cmd->value == RRB)
			ft_putstr_fd("RRB", 1);
		if (cmd->value == RRR)
			ft_putstr_fd("RRR", 1);
}

void	put_command(s_stack *cmd)
{
	while (cmd->prev->value != DUMMY)
	{
		cmd = cmd->next;
	}
	while(cmd->value != DUMMY)
	{
		put_selected_command(cmd);
		write(1, "\n", 1);
		cmd = cmd->next;
	}
}