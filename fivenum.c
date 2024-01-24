/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:53 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/24 15:33:03 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	five_digit(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->content != minimal_finder(*stack_a))
		ra_rotate(stack_a);
	pb_push(stack_a,stack_b);
	if (ft_lstsize(*stack_a) > 3)
	{
	while ((*stack_a)->content != biggest_finder(*stack_a))
		ra_rotate(stack_a);	
	pb_push(stack_a,stack_b);
	}
	sort_three_numbers(three_digit(*stack_a), stack_a);
	pa_push(stack_a,stack_b);
	if (ft_lstsize(*stack_b) != 0)
	{
		ra_rotate(stack_a);
		pa_push(stack_a, stack_b);
	}
	
	return (0);
}

// void sort_five_num(t_list **stack_a)
// {
// 	t_list *temp;

// 	temp = *stack_a;
// 	if (temp->content > ft_lstlast(*stack_a)->content)
// 		ra_rotate(stack_a);
// 	else if (temp->content < temp->next->content)
// 		return ;
// 	else if (temp->content > temp->next->content && temp->content > temp->next->next->content && temp->content < ft_lstlast(*stack_a)->content)
// 		{
// 				rra_rotate(stack_a);
// 				sa_swap(stack_a);
// 				ra_rotate(stack_a);
// 				ra_rotate(stack_a);
			
// 		}
// 		else if (temp->content > temp->next->content)
// 			sa_swap(stack_a);
			
// }

