/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:12:33 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/17 13:07:18 by rtruvelo         ###   ########.fr       */
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
    t_list *stack_to;
    t_list *stack_from;

    stack_to = ft_lstduplicate(stack_a);
    stack_from = ft_lstduplicate(stack_b);

    i = 0;
    x = 0;
    while (i <= index)
    {
        num = stack_to->content;
        stack_to->index = i;
        stack_to->content = stack_to->next->content;
        i++;
    }    
    // ft_printf("%d\n", num);
    // if (check_is_minimal(stack_a,stack_b) == 1 && index == 0)
    //     i = 1;
    // else if (check_is_biggest(stack_a,stack_b) == 1 && index == 0)
    //     i = 1;
    // else
    // {
        if (i > count_mediane(stack_to))
        {
            i = (ft_lstsize(stack_to) - i) + 1;
            stack_to->second_part = 1;
        }
        if (num > stack_from->content)
            i = i + 1;
        // if (num < stack_b->content && (num < ft_lstadd_back(stack_b)->content))
        //     i = i + 2;
        else 
        {
            x = i;
            while (num < stack_from->content)
            {
                stack_from->content = stack_from->next->content;
                i++;
            }
            while (num > ft_lstlast(stack_from)->content)
            {
                ft_lstlast(stack_from)->content = stack_from->prev->content;
                x++;
            }
            if (x < i)
                i = x;
                
        }
    // }
    return (i);
}



