/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:38:24 by tkano             #+#    #+#             */
/*   Updated: 2021/07/07 14:38:24 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

# define True 1
# define False 0
# define SUCCESS 0
# define ERROR 1
# define DUMMY -2147483649

typedef struct	t_stack	{
	struct t_stack	*prev;
	long			value;
	struct t_stack	*next;
}				s_stack;

int		put_error(void);
int		add_stack(s_stack **v, int num);
int		set_stack(s_stack **a, s_stack **b, int argc, char **argv);
void	put_stack(s_stack *v);
void	clear_stack(s_stack **v);
int		finish_program(int flag, s_stack **a, s_stack **b);
void	do_ra(s_stack **a);
void	ft_put_ra(void);
void	do_sa(s_stack **a);
void	ft_put_sa(void);
void	do_sb(s_stack **a);
void	do_ss(s_stack **a, s_stack **b);
int		do_pb(s_stack **a, s_stack **b);
void	ft_put_pb(void);;
void	do_rra(s_stack **a);
void	ft_put_rra(void);
int		do_pa(s_stack **a, s_stack **b);
void	ft_put_pa(void);
long	pop(s_stack **v);
int		push(s_stack **v, long num);
void	do_rb(s_stack **b);
void	do_rr(s_stack **a, s_stack **b);
void	do_rrb(s_stack **b);
void	do_rrr(s_stack **a, s_stack **b);
int		error_check(int argc, char **argv);
void	sort_2(s_stack **a);
void	sort_3(s_stack **a);
int		sort_6(s_stack **a, s_stack **b);
int		sort_100(s_stack **a, s_stack **b);
int		stacklen(s_stack *v);
long	stackmin(s_stack **a, int *loc, int len);
long	stackmedian(s_stack **v);

#endif
