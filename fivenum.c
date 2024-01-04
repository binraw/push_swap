/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:53 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/04 16:38:31 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	five_digit(t_list **stack_a, t_list **stack_b)
{
	pb_push(stack_b,stack_a);
	pb_push(stack_b,stack_a);
	sort_three_numbers(three_digit(*stack_a), stack_a);
	pa_push(stack_a,stack_b);
	sort_five_num(stack_a);
	pa_push(stack_a,stack_b);
	sort_five_num(stack_a);
	return (0);
}

void sort_five_num(t_list **stack_a)
{
	if (stack_a->content > ft_lstlast(stack_a)->content)
		ra_rotate(stack_a);
	if (stack_a->content < stack_a->next->content)
		return ;
}

