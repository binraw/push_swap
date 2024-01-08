/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/08 16:07:00 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_digit(t_list **stack_a, t_list **stack_b)
{
	int y;
	
	
	pb_push(stack_a,stack_b);
	if (ft_lstsize(*stack_a) > 3)
		pb_push(stack_a,stack_b); 
	sort_two_elemb(stack_b);
// check les nombres de rotation
	y = index_to_push(stack_a, stack_b);
	if (y == 1)
		pb_push(stack_a,stack_b);
	
	
	return (0);
}

int index_to_push(t_lst *stack_a, t_list *stack_b)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	
	while (i < ft_lstsize(stack_a))
	{
		if (count_number_rotate(stack_a, stack_b, i) < count || i == 0)
		{
		count = count_number_rotate(stack_a, stack_b, i);
		y = i;  // nombre de l'index a push
		}
		if (count == 1)
			break ;
		i++;
	}
	return (y);
}