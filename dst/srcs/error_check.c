/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:57:13 by tkano             #+#    #+#             */
/*   Updated: 2021/10/06 21:17:40 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long long	ft_check(long long num)
{
	if (num > 2147483647 && num < 9223372036854775807L)
		return (DUMMY);
	else if (num < -2147483648 && num >= -9223372036854775807L)
		return (DUMMY);
	if (num >= 9223372036854775807L)
		return (DUMMY);
	else if (num < -9223372036854775807L)
		return (DUMMY);
	else
		return (num);
}

int	ft_isint(char *argv)
{
	int			i;
	long long	num;
	int			flag;

	i = 0;
	num = 0;
	flag = 1;
	while ((argv[i] >= '\t' && argv[i] <= '\r') || argv[i] == ' ')
		i++;
	if (argv[i] == '+')
		i++;
	else if (argv[i] == '-')
	{
		flag *= -1;
		i++;
	}
	while ((argv[i] <= '9' && argv[i] >= '0'))
	{
		num *= 10;
		num += (argv[i] - '0');
		i++;
	}
	if (ft_check(num * flag) == DUMMY)
		return (FALSE);
	return (TRUE);
}

int	ft_isnum(char *argv)
{
	size_t	s;
	size_t	i;

	s = ft_strlen(argv);
	if (ft_isdigit(argv[0]) == FALSE && argv[0] != '-')
		return (ERROR);
	if (argv[0] == '-' && ft_isdigit(argv[1]) == FALSE)
		return (ERROR);
	i = 1;
	while (i < s)
	{
		if (ft_isdigit(argv[i]) == FALSE)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	error_check(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == ERROR)
			return (ERROR);
		if (ft_isint(argv[i]) == FALSE)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
