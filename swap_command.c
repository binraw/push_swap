/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:15:15 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 14:13:22 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;

	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_printf("error command");
	tmp_val = head->content;
	head->content= next->content;
	next->content = tmp_val;
}

void sa_swap(t_list **stack_a)
{
	swap(stack_a);
    ft_printf("sa\n");
}
void sb_swap(t_list **stack_b)
{
	swap(stack_b);
    ft_printf("sb\n");
}

int ss_swap(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
        return (-1);
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
    return (0);
}
void	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
        head_to->prev = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
        tmp->prev = NULL;
		*stack_to = tmp;
	}
}

void	pa_push(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb_push(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*next_to;

	head = *stack;
	tail = ft_lstlast(head);
	next_to = tail->prev;
	tail->next = head;
	*stack = head->next;
	head->next = NULL;
	tail->prev = next_to;
    head->prev = tail;
}



void ra_rotate(t_list **stack_a)
{
	rotate(stack_a);
    ft_printf("ra\n");
}
void rb_rotate(t_list **stack_b)
{
	rotate(stack_b);
    ft_printf("rb\n");
}

void rr_rotate(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}
void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
    t_list  *next_to;

    head = *stack;
    tail = ft_lstlast(head);
    next_to = ft_lstlast2(head);
    next_to->next = NULL;
    tail->next = head;
    tail->prev = NULL;
    head->prev = tail;
    *stack = tail;
}

void	rra_rotate(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb_rotate(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

int	rrr_rotate(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}