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
	if (set_stack(&a, &b, argc, argv) == ERROR)
		return (finish_program(ERROR, &a, &b));
	//sentinel_a = get_sentinetal(a);
	write(1, "push_swap\n", 10);
	printf("v->main: %d\n", a->next->next->value);
	put_stack(a);
	printf("1st: %d", a->value);
	return (finish_program(SUCCESS, &a, &b));
}
