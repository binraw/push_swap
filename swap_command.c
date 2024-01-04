/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:15:15 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/04 14:16:56 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;


	// if (ft_lstsize(*stack) < 2)
	// 	return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_printf("error command");
	tmp_val = head->content;
	head->content= next->content;
	next->content = tmp_val;
	// return (0);
}

void sa_swap(t_list **stack_a)
{
    // if (swap(stack_a) == -1)
    // {
	// 	return (-1);
	// }
	swap(stack_a);
    ft_printf("sa\n");
    // return (0);
}
void sb_swap(t_list **stack_b)
{
    	// if (swap(stack_b) == -1)
        // 	return (-1);
	swap(stack_b);
    ft_printf("sb\n");
    // return (0);
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

	// if (ft_lstsize(*stack_from) == 0)
	// 	return (-1);
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
	// return (0);
}

void	pa_push(t_list **stack_a, t_list **stack_b)
{
	// if (push(stack_a, stack_b) == -1)
	// 	return (-1);
	push(stack_a, stack_b);
	ft_printf("pa\n");
	// return (0);
}

void	pb_push(t_list **stack_a, t_list **stack_b)
{
	// if (push(stack_b, stack_a) == -1)
	// 	return (-1);
	push(stack_b, stack_a);
	ft_printf("pb\n");
	// return (0);
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	// if (ft_lstsize(*stack) < 2)
	// 	return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
    head->prev = tail;
	// return (0);
}
void ra_rotate(t_list **stack_a)
{
    // if (rotate(stack_a) == -1)
	// 	return (-1);
	rotate(stack_a);
    ft_printf("ra\n");
    // return (0);
}
void rb_rotate(t_list **stack_b)
{
    // if (rotate(stack_b) == -1)
	// 	return (-1);
	rotate(stack_b);
    ft_printf("rb\n");
    // return (0);
}

void rr_rotate(t_list **stack_a, t_list **stack_b)
{
    // if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
    //     return (-1);
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
    // return (0);
}
void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
    t_list  *next_to;

	// if (ft_lstsize(*stack) < 2)
	// 	return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    next_to = tail->prev;
    next_to->next = NULL;
    tail->next = head;
    tail->prev = NULL;
    head->prev = tail;
    *stack = tail;
	// return (0);
}

void	rra_rotate(t_list **stack_a)
{
	// if (reverse_rotate(stack_a) == -1)
	// 	return (-1);
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	// return (0);
}

void	rrb_rotate(t_list **stack_b)
{
	// if (reverse_rotate(stack_b) == -1)
	// 	return (-1);
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	// return (0);
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