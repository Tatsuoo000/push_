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
	if(ft_check(num * flag) == DUMMY)
		return (False);
	return (True);
}

int	ft_isnum(char *argv)
{
	size_t	s;
	size_t	i;

	s = ft_strlen(argv);
	if (ft_isdigit(argv[0]) == False && argv[0] != '-')
		return (ERROR);
	if (argv[0] == '-' && ft_isdigit(argv[1]) == False)
		return(ERROR);
	i = 1;
	while (i < s)
	{
		if (ft_isdigit(argv[i]) == False)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_isdup(char **argv, int i, int argc)
{
	int	j;

	j = i + 1;
	while (j < argc)
	{
		if (ft_strcmp(argv[i], argv[j]) == False)
			return (False);
		j++;
	}
	return (True);
}

int	error_check(int argc, char **argv)
{
	int		i;

	i = 1;
	while(i < argc)
	{
		if (ft_isnum(argv[i]) == ERROR)
			return (ERROR);
		if (ft_isint(argv[i]) == False)
			return (ERROR);
		if (ft_isdup(argv, i, argc) == False)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
