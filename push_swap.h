/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/04 14:17:38 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_list
{
	int			content;
    struct s_list	*prev;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	is_empty_t_list(t_list *li);
void printListe(t_list *liste);
int	ft_lstsize(t_list *head);
// int	swap(t_list **stack);
int	rrr_rotate(t_list **stack_a, t_list **stack_b);
void	rrb_rotate(t_list **stack_b);
void	rra_rotate(t_list **stack_a);
void	reverse_rotate(t_list **stack);
void rr_rotate(t_list **stack_a, t_list **stack_b);
void rb_rotate(t_list **stack_b);
void ra_rotate(t_list **stack_a);
void	rotate(t_list **stack);
void	pb_push(t_list **stack_a, t_list **stack_b);
void	pa_push(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_to, t_list **stack_from);
int ss_swap(t_list **stack_a, t_list **stack_b);
void sb_swap(t_list **stack_b);
void sa_swap(t_list **stack_a);
void	swap(t_list **stack);












int three_digit(t_list *stack_a);
int	sort_three_numbers(int num, t_list **stack_a);
void sa_rra(t_list **stack_a);
void rra_sa(t_list **stack_a);
#endif