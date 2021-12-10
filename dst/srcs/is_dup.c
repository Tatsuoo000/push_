/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:19:16 by tkano             #+#    #+#             */
/*   Updated: 2021/12/08 09:19:16 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted_array(int *array, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if (array[i - 1] >= array[i])
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int move_half(int *array, int start, int end, int *temp)
{
    int i;
    int temp_end;
    int median;

    i = start;
    temp_end = end;
    median = (end - start) / 2 + start;
    while (i < temp_end)
	{
		if (array[i] < array[median])
		{
			temp[start] = array[i];
			++start;
		}
		else if (array[i] > array[median])
		{
			temp[end - 1] = array[i];
			--end;
		}
		else if (i != median)
			return (-1);
		++i;
	}
	temp[start] = array[median];
	return (start);
}

int     array_sort(int *array, int start, int end, int *temp)
{
    int median;

    if (end - start <= 1)
        return (SUCCESS);
    median = move_half(array, start, end, temp);
	if (median == -1)
        return (ERROR);
	int_cpy(array + start, temp + start, end - start);
	if (array_sort(array, start, median, temp))
		return (ERROR);
	if (array_sort(array, median + 1, end, temp))
		return (ERROR);
	return (SUCCESS);
}


void    stack_to_array(s_stack *a, int *array)
{
    while (a->value != DUMMY)
    {
        *array = a->value;
        ++array;
        a = a->next;
    }
}

int	    ft_isdup(s_stack **a)
{
	int	n;
    int *sorted;
    int *temp;

	n = stacklen(*a);
    temp = NULL;
    if (ft_malloc(&sorted, sizeof(int), n) || ft_malloc(&temp, sizeof(int), n))
    {
        free(temp);
        free(sorted);
        return (ERROR);
    }
    stack_to_array(*a, sorted);
    if (!array_sort(sorted, 0, n, temp))
		n = is_sorted_array(sorted, n);
	replacement_to_index(*a, sorted);
	free(temp);
	free(sorted);
	return (n);
}
