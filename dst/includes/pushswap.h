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

typedef struct	t_stack	{
	struct t_stack	*prev;
	int				value;
	struct t_stack	*next;
}				s_stack;

int		put_error(void);
int		add_stack(s_stack **v, int num);
int		set_stack(s_stack **a, s_stack **b, int argc, char **argv);
void	put_stack(s_stack *v);
void	clear_stack(s_stack **v);
int		finish_program(int flag, s_stack **a, s_stack **b);

#endif
