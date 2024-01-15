/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:12:33 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/15 15:09:20 by rtruvelo         ###   ########.fr       */
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
    int x;

    i = 0;
    x = 0;
    while (i <= index)
    {
        num = stack_a->content;
        stack_a->index = i;
        stack_a->content = stack_a->next->content;
        i++;
    }    
    // ft_printf("%d\n", num);
    // if (check_is_minimal(stack_a,stack_b) == 1 && index == 0)
    //     i = 1;
    // else if (check_is_biggest(stack_a,stack_b) == 1 && index == 0)
    //     i = 1;
    // else
    // {
        if (i > count_mediane(stack_a))
        {
            i = (ft_lstsize(stack_a) - i) + 1;
            stack_a->second_part = 1;
        }
        if (num > stack_b->content)
            i = i + 1;
        // if (num < stack_b->content && (num < ft_lstadd_back(stack_b)->content))
        //     i = i + 2;
        else 
        {
            x = i;
            while (num < stack_b->content)
            {
                stack_b->content = stack_b->next->content;
                i++;
            }
            while (num > ft_lstlast(stack_b)->content)
            {
                ft_lstlast(stack_b)->content = stack_b->prev->content;
                x++;
            }
            if (x < i)
                i = x;
                
                
        }
    // }
    return (i);
}



