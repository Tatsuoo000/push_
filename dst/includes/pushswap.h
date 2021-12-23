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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR 1
# define STDERR 2
# define DUMMY -2147483649

typedef enum e_cmd{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_cmd;
typedef struct s_ft_stack{
	struct s_ft_stack	*prev;
	long				value;
	struct s_ft_stack	*next;
}						t_ft_stack;

typedef struct s_info{
	t_ft_stack	*ans;
	t_ft_stack	*a;
	t_ft_stack	*b;
	long		size;
	long		min_value;
	long		median;
}				t_info;

int		put_error(void);
int		add_stack(t_ft_stack **v, int num);
int		set_stack(t_ft_stack **a, t_ft_stack **b, int argc, char **argv);
void	put_stack(t_ft_stack *v);
void	clear_stack(t_ft_stack **v);
int		finish_program(int flag, t_ft_stack **a, t_ft_stack **b, t_info **info);
void	do_ra(t_ft_stack **a);
void	ft_put_ra(void);
void	do_sa(t_ft_stack **a);
void	ft_put_sa(void);
void	do_sb(t_ft_stack **a);
void	do_ss(t_ft_stack **a, t_ft_stack **b);
int		do_pb(t_ft_stack **a, t_ft_stack **b);
void	ft_put_pb(void);;
void	do_rra(t_ft_stack **a);
void	ft_put_rra(void);
int		do_pa(t_ft_stack **a, t_ft_stack **b);
void	ft_put_pa(void);
long	pop(t_ft_stack **v);
int		push(t_ft_stack **v, long num);
void	do_rb(t_ft_stack **b);
void	do_rr(t_ft_stack **a, t_ft_stack **b);
void	do_rrb(t_ft_stack **b);
void	do_rrr(t_ft_stack **a, t_ft_stack **b);
int		error_check(int argc, char **argv);
int		sort_2(t_info **info);
int		sort_3(t_info **info);
int		sort_6(t_info **info);
int		sort_100(t_info **info);
int		stacklen(t_ft_stack *v);
long	stackmin(t_ft_stack **a, int *loc, int len);
long	stackmedian(t_ft_stack **v);
int		info_init(t_ft_stack **a, t_ft_stack **b, t_info **info, int argc);
int		init_stack(t_ft_stack **v);
int		is_sorted(t_ft_stack *v);
int		ft_isdup(t_ft_stack **a);
int		first_half_set(t_info **info, int median);
void	int_cpy(int *p, const int *s, size_t n);
void	replacement_to_index(t_ft_stack *a, int *array);
int		add_ans_pa(t_info **info);
int		add_ans_pb(t_info **info);
int		add_ans_sa(t_info **info);
int		add_ans_sb(t_info **info);
int		add_ans_ra(t_info **info);
int		add_ans_rb(t_info **info);
int		add_ans_rra(t_info **info);
int		add_ans_rrb(t_info **info);
void	put_command(t_ft_stack *cmd);
int		command_loop(t_info **info, int loop, int cmd);
int		command_exec(t_info **info, int cmd);
int		pa_ra_set(t_info **info, int n);
int		pa_ra_min(t_info **info, int *start);
int		sa_min(t_info **info);
int		pa_or_ra_min(t_info **info, int *start);
int		b_quicksort(t_info **info, int start, int end);
int		b_half_set(t_info **info, int *start, int middle, int end);
int		quicksort_second(t_info **info, int *middle, int end);
int		swap_push(t_info **info);
void	opt_ans_rr(t_ft_stack *cmd);
void	opt_ans_pp(t_ft_stack *cmd);

#endif
