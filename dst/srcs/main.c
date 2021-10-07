/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:49:16 by tkano             #+#    #+#             */
/*   Updated: 2021/07/08 17:49:16 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	s_stack	*a;
	s_stack	*b;
	//s_stack	*sentinel_a;
	//s_stack	*sentinel_b;

	a = NULL;
	b = NULL;
	if (error_check(argc, argv) == ERROR)
		return (put_error());
	if (set_stack(&a, &b, argc, argv) == ERROR)
		return (finish_program(ERROR, &a, &b));
	//sentinel_a = get_sentinetal(a);
	write(1, "push_swap\n", 10);
	//printf("v->main: %d\n", a->next->next->value);
	//put_stack(a);
	if (argc == 1 || argc == 2)
		return (finish_program(SUCCESS, &a, &b));
	else if (argc == 3)
		(sort_2(&a));
	else if (argc == 4)
		sort_3(&a);
	else if (argc <= 7)
		sort_6(&a, &b);
	else if (argc <= 101)
		sort_100(&a, &b);
	put_stack(a);
	put_stack(b);
	//printf("1st: %d", a->value);
	return (finish_program(SUCCESS, &a, &b));
}
