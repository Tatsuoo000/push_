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

void	put_stack(t_ft_stack *v)
{
	printf("=======stack=====\n");
	while (v->prev->value != DUMMY)
	{
		v = v->next;
	}
	while (v->value != DUMMY)
	{
		ft_putnbr_fd(v->value, 1);
		write(1, "\n", 1);
		v = v->next;
	}
}

void	put_selected_command(t_ft_stack *cmd)
{
	if (cmd->value == PA)
		ft_putstr_fd("pa", 1);
	if (cmd->value == PB)
		ft_putstr_fd("pb", 1);
	if (cmd->value == SA)
		ft_putstr_fd("sa", 1);
	if (cmd->value == SB)
		ft_putstr_fd("sb", 1);
	if (cmd->value == SS)
		ft_putstr_fd("ss", 1);
	if (cmd->value == RA)
		ft_putstr_fd("ra", 1);
	if (cmd->value == RB)
		ft_putstr_fd("rb", 1);
	if (cmd->value == RR)
		ft_putstr_fd("rr", 1);
	if (cmd->value == RRA)
		ft_putstr_fd("rra", 1);
	if (cmd->value == RRB)
		ft_putstr_fd("rrb", 1);
	if (cmd->value == RRR)
		ft_putstr_fd("rrr", 1);
}

void	put_command(t_ft_stack *cmd)
{
	while (cmd->prev->value != DUMMY)
	{
		cmd = cmd->next;
	}
	opt_ans_rr(cmd);
	while (cmd->prev->value != DUMMY)
	{
		cmd = cmd->next;
	}
	opt_ans_pp(cmd);
	while (cmd->value != DUMMY)
	{
		put_selected_command(cmd);
		write(1, "\n", 1);
		cmd = cmd->next;
	}
}
