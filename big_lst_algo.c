/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/17 12:40:05 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	transfer_num_ra(t_list *stack_a, t_list *stack_b, int index)
{
	int count;
	int x;
	t_list *stack_from;

	stack_from = ft_lstduplicate(stack_b);
	
	count = count_number_rotate(stack_a, stack_b, index);// il reste seulement les operations a faire dans b
	while (index >= 0)
	{
		ra_rotate(&stack_a);
		index--;
	}
	index = count;
	while (count != 0)  //check si c'est le bon sens
	{
		if (stack_a->content > stack_from->next->content)
			x = 1;
		stack_from->next->content = stack_from->next->next->content;
		count--;
	}
	count = index;
	if (x == 0)
	{
		while (index != 0)
		{
			rrb_rotate(&stack_b);
			index--;
		}
		pb_push(&stack_a, &stack_b);
		while (count != 0)
		{
			rb_rotate(&stack_b); // je remet dans le bon ordre stack_b
			count--;
		}
	}
	count = index;
	if (x == 1 && index != 1) // ici le != 1 c'est pour faire seulement un swap dans ce cas la 
	{
		while (index != 0)
		{
			rb_rotate(&stack_b);
			index--;
		}
		pb_push(&stack_a, &stack_b);
		
		while (count != 0)
		{
			rrb_rotate(&stack_b); // je remet dans le bon ordre stack_b
			count--;
		}
	}
	if (x == 1 && index == 1) // ici quand il suffit de swap les deux premiers
	{
		pb_push(&stack_a, &stack_b);
		sb_swap(&stack_b);
	}
}
void	transfer_num_rra(t_list *stack_a, t_list *stack_b, int index)
{
	int count;
	int x;
	int pos;
	t_list *stack_from;

	stack_from = ft_lstduplicate(stack_b);
	

	pos = ft_lstsize(stack_a);   //possiblement la solution pour savoir combien de fois il reste a rra 
	
	count = count_number_rotate(stack_a, stack_b, index);
		while (index != 0)
		{
			rra_rotate(&stack_a);
			index = pos - index;
		}
		index = count;
	if (stack_a->content > ft_lstlast(stack_b)->content)
	{
		pb_push(&stack_a, &stack_b);
		rb_rotate(&stack_b);
		return ;
	}
	while (count >= 0)  //check si c'est le bon sens
	{
		if (stack_a->content > stack_from->next->content)
			x = 1;
		stack_from->next->content = stack_from->next->next->content;
		count--;
	}
	count = index;
	if (x == 0)
	{
		while (index != 0)
		{
			rrb_rotate(&stack_b);
			index--;
		}
		pb_push(&stack_a, &stack_b);
		while (count != 0)
		{
			rb_rotate(&stack_b); // je remet dans le bon ordre stack_b
			count--;
		}
	}
	count = index;
	if (x == 1 && index != 1) // ici le != 1 c'est pour faire seulement un swap dans ce cas la 
	{
		while (index != 0)
		{
			rb_rotate(&stack_b);
			index--;
		}
		pb_push(&stack_a, &stack_b);
		
		while (count != 0)
		{
			rrb_rotate(&stack_b); // je remet dans le bon ordre stack_b
			count--;
		}
	}
	if (x == 1 && index == 1) // ici quand il suffit de swap les deux premiers
	{
		pb_push(&stack_a, &stack_b);
		printListe(stack_b);
	}
}
int	big_digit(t_list **stack_a, t_list **stack_b)
{
	int y;
	int x;
	
	x = 0;
	pb_push(stack_a,stack_b);
	printListe(*stack_a);
	// printListe(*stack_a);
	if (ft_lstsize(*stack_a) > 3)
	{
		pb_push(stack_a,stack_b); 
		
		printListe(*stack_b);
		printListe(*stack_a);
	}
	// sort_two_elemb(*stack_b);
// Vers ici des problemes !!!

while (ft_lstsize(*stack_a) > 3)
{
	y = index_to_push(*stack_a, *stack_b);
	if (y == 1)
		pb_push(stack_a,stack_b); // je pousse si le chiffre est le plus grand direct
	 if (y <= count_mediane(*stack_a)) // ici c'est si le chiffre est en dessous de la mediane de stack_a
		 transfer_num_ra(*stack_a, *stack_b, y);
	else // ICI COMMENCE DE L'AUTRE SENS c'est exactement la meme  sinon
	{
		transfer_num_rra(*stack_a, *stack_b, y);
		printListe(*stack_b);
	}
	
}
 sort_three_numbers(three_digit(*stack_a), stack_a);
	// printListe(*stack_b);
	return (0);
}

int index_to_push(t_list *stack_a, t_list *stack_b)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	
	while (i <= ft_lstsize(stack_a))
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