/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:34:14 by tkano             #+#    #+#             */
/*   Updated: 2021/12/06 21:34:14 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int is_sorted(s_stack *v)
{
    s_stack *tmp;

    tmp = v;
    while (tmp->next->value != DUMMY)
    {
        if (tmp->value > tmp->next->value)
            return (False);
        tmp = tmp->next;
    }
    return (True);
}
