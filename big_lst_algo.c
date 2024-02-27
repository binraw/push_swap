/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/27 12:55:30 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rr_transfer(t_list **stack_a, t_list **stack_b, int index)
{
	int count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (index >= 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int rr_transfer_count(t_list **stack_a, t_list **stack_b, int index)
{
	int count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (count > 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int ra_transfer(t_list **stack_a,  int index)
{
	while (index >= 0)
	{
		ra_rotate(stack_a);
		index--;
	}
	return (index);
}

int rb_transfer(t_list **stack_b, int count)
{
	while (count > 0)
		{
			rb_rotate(stack_b);
			count--;
		}
		return (count);
}

int rrb_transfer(t_list **stack_b, int count)
{
			count = ft_lstsize(*stack_b) - count;
		while (count > 0)
		{
			rrb_rotate(stack_b);
			count--;
		}
		return (count);
}

int	rr_transfer_combi(t_list **stack_a, t_list **stack_b, int index)
{
	int count;
	int x;

	x = index;
	count = count_number_rota(stack_b, (*stack_a)->content);
	if (index < count)
			index = rr_transfer(stack_a, stack_b, index);
		count = count - (x - index);
		x = index;
		if (count < index)
			index = rr_transfer_count(stack_a, stack_b, index);
		count = count - (x - index);
	return (count);
}

void	transfer_num_ra(t_list **stack_a, t_list **stack_b, int index)
{
	int count;
	int x;
	t_list *stack_from;

	x = index;
	stack_from = ft_lstduplicate(*stack_b);
	count = count_number_rota(stack_b, (*stack_a)->content);
	if (index == 0 && count == 1)
		rr_rotate(stack_a, stack_b);
	if (index >=0 && count > 0)
		count = rr_transfer_combi(stack_a, stack_b, index);
	index =  ra_transfer(stack_a, index);
	if (count <= count_mediane(*stack_b))
		count = rb_transfer(stack_b, count);
	else
		count = rrb_transfer(stack_b, count);
	pb_push(stack_a, stack_b);
	ft_lstclear(&stack_from, free);
}

void	transfer_num_rra(t_list **stack_a, t_list **stack_b, int index)
{
	int count;
	int pos;
	t_list *stack_from;

	stack_from = ft_lstduplicate(*stack_b);
	pos = ft_lstsize(*stack_a);
	while (index >= 0)
	{
		rra_rotate(stack_a);
		index--;
	}
	count = count_number_rota(stack_b, (*stack_a)->content);
	while (count > 0)
	{
		rrb_rotate(stack_b);
		count--;
	}
	pb_push(stack_a, stack_b);
	ft_lstclear(&stack_from, free);
}


int	big_digit(t_list **stack_a, t_list **stack_b)
{
	int y;
	int x;
	
	x = 0;
	pb_push(stack_a,stack_b);
	if (ft_lstsize(*stack_a) > 3)
		pb_push(stack_a,stack_b);
	sort_two_elemb(*stack_b);
while (ft_lstsize(*stack_a) > 3)
{
	y = index_to_push(*stack_a, *stack_b);
	if (y <= count_mediane(*stack_a))
		transfer_num_ra(stack_a, stack_b, y);
	else
		transfer_num_rra(stack_a, stack_b, y);
}
 sort_three_numbers(three_digit(*stack_a), stack_a);
 while (ft_lstsize(*stack_b) > 0 )
	x = big_digit_to_a(stack_a, stack_b);
orga_lst(stack_a);
	return (0);
}

int index_to_push(t_list *stack_a, t_list *stack_b)
{
	int i;
	int x;
	int count;
	t_list *tmp;
	
	tmp = ft_lstduplicate(stack_a);
	i = 0;
	x = 0;
	count = 0;
	while (i <= ft_lstsize(stack_a))
	{
		if (count_number_rota(&stack_b, tmp->content) < count || i == 0)
		{
		count = count_number_rota(&stack_b, tmp->content);
		x = i;
		}
		if (count == 1)
			break ;
		tmp->content = tmp->next->content;
		i++;
	}
	ft_lstclear(&tmp, free);
	return (x);
}


void	ft_combi_clear(t_list **tmp, t_list **dupli_a)
{
	ft_lstclear(tmp, free);
	ft_lstclear(dupli_a, free);
}
int big_digit_to_a(t_list **stack_a, t_list **stack_b)
{
	int count;
	t_list *tmp;
	t_list *dupli_a;
	
	tmp = ft_lstduplicate(*stack_b);
	dupli_a = ft_lstduplicate(*stack_a);
	count = count_number_rota_a(stack_a, tmp->content);
	if (tmp->content > biggest_finder(*stack_a))
		push_minimal(stack_a, stack_b);
	else if (tmp->content < dupli_a->content &&  tmp->content > ft_lstlast(dupli_a)->content)
		pa_push(stack_a, stack_b);
	else if (tmp->content < ft_lstlast(dupli_a)->content && tmp->content > minimal_finder(*stack_a) )
		rra_rotate(stack_a);
	else if (tmp->content < dupli_a->content && dupli_a->content == minimal_finder(*stack_a))
		pa_push(stack_a, stack_b);
	else if (ft_lstsize(*stack_b) == 1 && tmp->content < minimal_finder(*stack_a))
		orga_papush(stack_a, stack_b);
	else if (tmp->content < dupli_a->content && tmp->content > dupli_a->next->content)
		papush_sa(stack_a, stack_b);
	else if ((tmp->content < dupli_a->content && tmp->content > ft_lstlast(dupli_a)->content) /*|| (tmp->content > dupli_a->content && tmp->content < ft_lstlast(dupli_a)->content ) */)
		pa_push(stack_a, stack_b);
	else 
		orga_lst_order(stack_a, stack_b);
	ft_combi_clear(&tmp, &dupli_a);
	return (0);
}

void	push_minimal(t_list **stack_a, t_list **stack_b)
{
	orga_lst(stack_a);
	pa_push(stack_a, stack_b);
	ra_rotate(stack_a);	
}

void	orga_papush(t_list **stack_a, t_list **stack_b)
{
	orga_lst(stack_a);
	pa_push(stack_a, stack_b);
}

void	papush_sa(t_list **stack_a, t_list **stack_b)
{
	pa_push(stack_a, stack_b);
	sa_swap(stack_a);
}

int orga_lst(t_list **stack_a)
{
	if (ft_find_index(*stack_a, minimal_finder(*stack_a)) > count_mediane(*stack_a) )
	{
		while ((*stack_a)->content != minimal_finder(*stack_a))
		rra_rotate(stack_a);
	}
	else 
	{
		while ((*stack_a)->content != minimal_finder(*stack_a))
			ra_rotate(stack_a);
	}
	return (0);
}
int orga_lst_order(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	t_list *dupli_a;
	
	tmp = ft_lstduplicate(*stack_b);
	dupli_a = ft_lstduplicate(*stack_a);

	while ((*stack_a)->content != minimal_finder(*stack_a))
	{
		 if (tmp->content < ft_lstlast(*stack_a)->content && tmp->content > minimal_finder(*stack_a))
		 {
			break ;
		 } 	
		ra_rotate(stack_a);
	}
	ft_lstclear(&tmp, free);
	ft_lstclear(&dupli_a, free);
	return (0);
}
