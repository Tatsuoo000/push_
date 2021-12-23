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

int	sort(int argc, t_info **info)
{
	if (argc == 3)
	{
		if (sort_2(info))
			return (ERROR);
	}
	else if (argc == 4)
	{
		if (sort_3(info))
			return (ERROR);
	}
	else if (argc <= 7)
	{
		if (sort_6(info))
			return (ERROR);
	}
	else
		if (sort_100(info))
			return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_ft_stack	*a;
	t_ft_stack	*b;
	t_info		*info;

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
	if (argc == 1 || argc == 2)
		return (finish_program(SUCCESS, &a, &b, &info));
	else
		if (sort(argc, &info))
			return (finish_program(SUCCESS, &a, &b, &info));
	put_command(info->ans);
	return (finish_program(SUCCESS, &a, &b, &info));
}
