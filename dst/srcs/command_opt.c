/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:59:25 by tkano             #+#    #+#             */
/*   Updated: 2021/12/23 20:35:38 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	delete_stack(t_ft_stack *ans, int command)
{
	t_ft_stack	*tmp;

	tmp = ans->next->next;
	free(ans->next);
	ans->next = NULL;
	ans->value = command;
	ans->next = tmp;
	tmp->prev = ans;
}

void	opt_ans_rr(t_ft_stack *cmd)
{
	t_ft_stack	*tmp;

	tmp = cmd->next;
	while (tmp->value != DUMMY)
	{
		if (tmp->value == RA && tmp->next->value == RB)
			delete_stack(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			delete_stack(tmp, RR);
		if (tmp->value == RRA && tmp->next->value == RRB)
			delete_stack(tmp, RR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			delete_stack(tmp, RRR);
		if (tmp->value == SA && tmp->next->value == SB)
			delete_stack(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			delete_stack(tmp, SS);
		tmp = tmp->next;
	}
}

t_ft_stack	*dlst_delone(t_ft_stack *dstack)
{
	t_ft_stack	*prev1;
	t_ft_stack	*next1;

	prev1 = dstack->prev;
	next1 = dstack->next;
	free(dstack);
	prev1->next = next1;
	next1->prev = prev1;
	return (next1);
}

void	opt_ans_pp(t_ft_stack *cmd)
{
	t_ft_stack	*tmp;
	int			flag;

	tmp = cmd->next;
	while (tmp->value != DUMMY)
	{
		flag = FALSE;
		if (tmp->value == PA && tmp->next->value == PB)
			flag = TRUE;
		if (tmp->value == PB && tmp->next->value == PA)
			flag = TRUE;
		if (flag)
		{
			tmp = dlst_delone(tmp);
			tmp = dlst_delone(tmp);
			tmp = tmp->prev->prev;
		}
		tmp = tmp->next;
	}
}
