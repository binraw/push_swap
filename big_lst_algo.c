/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/23 15:03:25 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_num_ra(t_list **stack_a, t_list **stack_b, int index)
{
	int count;
	int x;
	t_list *stack_from;

	x = 0;

	stack_from = ft_lstduplicate(*stack_b);
	
	// il reste seulement les operations a faire dans b
	while (index >= 0)
	{
		ra_rotate(stack_a);
		printListe(*stack_a);
		index--;
	}
	count = count_number_rota(stack_b, (*stack_a)->content);
	ft_printf("valeur de count : %d\n", count);
	while (count > 0)
	{
		rb_rotate(stack_b);
		printListe(*stack_b);
		count--;
	}
	pb_push(stack_a, stack_b);
	printListe(*stack_b);
	

}
void	transfer_num_rra(t_list **stack_a, t_list **stack_b, int index)
{
	int count;
	int pos;
	t_list *stack_from;

	stack_from = ft_lstduplicate(*stack_b);
	

	pos = ft_lstsize(*stack_a);   //possiblement la solution pour savoir combien de fois il reste a rra 
	
	
	while (index >= 0)
	{
		rra_rotate(stack_a);
		printListe(*stack_a);
		index--;
	}
	count = count_number_rota(stack_b, (*stack_a)->content);
	ft_printf("valeur de count : %d\n", count);
	while (count > 0)
	{
		rb_rotate(stack_b);
		count--;
		printListe(*stack_b);
	}
	pb_push(stack_a, stack_b);
	printListe(*stack_b);
	

}


int	big_digit(t_list **stack_a, t_list **stack_b)
{
	int y;
	int x;
	
	x = 0;
	pb_push(stack_a,stack_b);
	printListe(*stack_a);
	if (ft_lstsize(*stack_a) > 3)
	{
		pb_push(stack_a,stack_b);
		
		printListe(*stack_b);
		printListe(*stack_a);
	}
	sort_two_elemb(*stack_b);


while (ft_lstsize(*stack_a) > 3)
{
	y = index_to_push(*stack_a, *stack_b);
	 if (y <= count_mediane(*stack_a))  // ici c'est si le chiffre est en dessous de la mediane de stack_a
	 {
		transfer_num_ra(stack_a, stack_b, y);
		// sorting_second_stack(stack_b);
		printListe(*stack_b);
	 } 
		 
	else // ICI COMMENCE DE L'AUTRE SENS c'est exactement la meme  sinon
	{
		transfer_num_rra(stack_a, stack_b, y);
		// sorting_second_stack(stack_b);
		printListe(*stack_b);
	}
	
}
 sort_three_numbers(three_digit(*stack_a), stack_a);
  
 while (ft_lstsize(*stack_b) > 0 && x < 100)
 {
	 big_digit_to_a(stack_a, stack_b);
	 x++;
	 
	
 }
 if (ft_find_index(*stack_a,minimal_finder(*stack_a)) <= count_mediane(*stack_a))
 {
	orga_lst(stack_a);
 }
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
	return (x);
}

int big_digit_to_a(t_list **stack_a, t_list **stack_b)
{
	int count;
	int x;

	t_list *tmp;
	t_list *dupli_a;
	
	tmp = ft_lstduplicate(*stack_b);
	dupli_a = ft_lstduplicate(*stack_a);
	x = 0;
	count = count_number_rota_a(stack_a, tmp->content);

	// ft_printf("Valeur de count final : %d\n", count);

	// choisir quel action realiser 
	printListe(*stack_a);
	printListe(*stack_b);
	if (tmp->content > biggest_finder(*stack_a))
	{
		pa_push(stack_a, stack_b);
		ra_rotate(stack_a);
	}
	else if (tmp->content < dupli_a->content &&  tmp->content > ft_lstlast(dupli_a)->content)
	{
		pa_push(stack_a, stack_b);
	}
	else if (tmp->content < ft_lstlast(dupli_a)->content && tmp->content > minimal_finder(*stack_a))
	{
		rra_rotate(stack_a);
		return (1);
	}
	else if (tmp->content < dupli_a->content && dupli_a->content == minimal_finder(*stack_a))
	{
		pa_push(stack_a, stack_b);
	}
	else 
	{
		orga_lst(stack_a);
	}
	// else if ()
	
	// if (calculate_ra(stack_a, stack_b, count))
	// 	push_after_ra(stack_a, stack_b, count);
	// else if (calculate_rra(stack_a, stack_b, count))
	// 	push_after_rra(stack_a, stack_b, count);

	return (0);
}

int orga_lst(t_list **stack_a)
{
	while ((*stack_a)->content != minimal_finder(*stack_a))
	{
		ra_rotate(stack_a);
	}
	return (0);
}
int orga_lst_rra(t_list **stack_a)
{
	while ((*stack_a)->content != minimal_finder(*stack_a))
	{
		rra_rotate(stack_a);
	}
	return (0);
}

// int calculate_ra(t_list **stack_a, t_list **stack_b, int count)
// {
// 	t_list *tmp;
// 	t_list *tmp_two;

// 	tmp = ft_lstduplicate(*stack_a);
// 	tmp_two = ft_lstduplicate(*stack_b);

// 	while (count >= 0)
// 	{
// 		ra_rotate(&tmp);
// 		count--;
// 	}
// 	if (tmp_two->content < tmp->content && tmp_two->content < ft_lstlast(tmp)->content)
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

// int calculate_rra(t_list **stack_a, t_list **stack_b, int count)
// {
// 	t_list *tmp;
// 	t_list *tmp_two;

// 	tmp = ft_lstduplicate(*stack_a);
// 	tmp_two = ft_lstduplicate(*stack_b);

// 	while (count >= 0)
// 	{
// 		rra_rotate(&tmp);
// 		count--;
// 	}
// 	if (tmp_two->content < tmp->content && tmp_two->content < ft_lstlast(tmp)->content)
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

// int push_after_ra(t_list **stack_a, t_list **stack_b, int count)
// {
// 	while (count >= 0)
// 	{
// 		ra_rotate(stack_a);
// 		count--;
// 	}
// 	pa_push(stack_a, stack_b);
// 	return (0);
// }

// int push_after_rra(t_list **stack_a, t_list **stack_b, int count)
// {
// 	while (count >= 0)
// 	{
// 		rra_rotate(stack_a);
// 		count--;
// 	}
// 	pa_push(stack_a, stack_b);
// 	return (0);
// }