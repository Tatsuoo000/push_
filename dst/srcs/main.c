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
	s_info	*info;
	//s_stack	*sentinel_a;
	//s_stack	*sentinel_b;

	a = NULL;
	b = NULL;
	if (error_check(argc, argv) == ERROR)
		return (put_error());
	if (set_stack(&a, &b, argc, argv) == ERROR)
		return (finish_program(ERROR, &a, &b, &info));
	if (info_init(&a, &b, &info, argc) == ERROR)
		return (finish_program(ERROR, &a, &b, &info));
	if (is_sorted(a))
		return (finish_program(SUCCESS, &a, &b, &info));
	if (ft_isdup(&a))
		return (finish_program(ERROR, &a, &b, &info));
	//sentinel_a = get_sentinetal(a);
	//write(1, "push_swap\n", 10);
	//printf("v->main: %d\n", a->next->next->value);
	//put_stack(a);
	if (argc == 1 || argc == 2)
		return (finish_program(SUCCESS, &a, &b, &info));
	else if (argc == 3)
		(sort_2(&info));
	else if (argc == 4)
		sort_3(&info);
	else if (argc <= 7)
		sort_6(&info);
	else
		sort_100(&info);
	//put_stack(a);
	//put_stack(b);
	put_command(info->ans);
	//printf("1st: %d", a->value);
	return (finish_program(SUCCESS, &a, &b, &info));
}
