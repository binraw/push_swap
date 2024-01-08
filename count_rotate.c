/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:12:33 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:59 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_mediane(t_list *stack_a)
{
    int i;

    i = 0;
    i =	ft_lstsize(stack_a);
    i = i / 2;

    return (i);
}

int     count_number_rotate(t_list *stack_a, t_list *stack_b, int index)
{
    int num;
    int i;

    i = 0;
    while (i < index)
    {
        num = stack_a->content;
        stack_a = stack_a->next;
        i++;
    }    
    if (check_is_minimal(stack_a,stack_b) == 1 && index == 0)
        i = 1;
    else if (check_is_biggest(stack_a,stack_b) == 1 && index == 0)
        i = 1;
    else
    {
        if (i > count_mediane(stack_a))
            i = i / 2;
        if (num > stack_b)
            i = i + 1;
        if (num < stack_b && num < ft_lstadd_back(stack_b))
            i = i + 2;
    }
    return (i);
}

