/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:08:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 14:12:37 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_transfer(t_list **stack_a, t_list **stack_b, int index)
{
	int	count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (index >= 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int	rr_transfer_count(t_list **stack_a, t_list **stack_b, int index)
{
	int	count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (count > 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int	ra_transfer(t_list **stack_a, int index)
{
	while (index > 0)
	{
		ra_rotate(stack_a);
		index--;
	}
	return (index);
}

int	rb_transfer(t_list **stack_b, int count)
{
	while (count > 0)
	{
		rb_rotate(stack_b);
		count--;
	}
	return (count);
}

int	rrb_transfer(t_list **stack_b, int count)
{
	count = ft_lstsize(*stack_b) - count;
	while (count > 0)
	{
		rrb_rotate(stack_b);
		count--;
	}
	return (count);
}
