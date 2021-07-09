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

	a = NULL;
	b = NULL;
	if (set_stack(&a, &b, argc, argv) == ERROR)
		return (put_error());
	write(1, "push_swap\n", 10);
	printf("1st: %d", a->prev->prev->prev->prev->prev->prev->prev->prev->value);
	return (0);
}
