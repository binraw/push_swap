/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/22 12:53:40 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     biggest_finder(t_list *lst)
{
	if (!lst)
		return (0);
    int biggest;
    biggest = lst->content;
    while (lst != NULL)
    {
        if (biggest <= lst->content)
            biggest = lst->content;
        lst = lst->next;
    }
    return (biggest);
}

int		minimal_finder(t_list *lst)
{
	int minimal;
	
	minimal = lst->content;
	 while (lst != NULL)
    {
        if (minimal >= lst->content)
            minimal = lst->content;
        lst = lst->next;
    }
    return (minimal);
}
int	ft_find_index(t_list *a, int nbr)
{
	int		i;

	i = 0;
	while (a->content != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
int ft_find_place_b(t_list *stack_b, int nbr_push)
{
    int i;
    t_list *tmp;
	t_list *stack_from;
    
	stack_from = ft_lstduplicate(stack_b);
    i = 1;
    if(nbr_push > stack_from->content && nbr_push < ft_lstlast(stack_from)->content)
		i = 0;
	else if (nbr_push > biggest_finder(stack_from) || nbr_push < minimal_finder(stack_from))
		i = ft_find_index(stack_from , biggest_finder(stack_b));
	else
	{
		tmp = stack_from->next;
		while (stack_from->content < nbr_push || tmp->content > nbr_push)
		{
			stack_from  = stack_from->next;
			tmp = stack_from->next;
			i++;
		}
	}
	ft_lstclear(&stack_from, free);
	
	return (i);
}
int ft_find_place_a(t_list *stack_a, int nbr_push)
{
    int i;
    t_list *tmp;
	t_list *stack_from;
	t_list *first;
    
	stack_from = ft_lstduplicate(stack_a);
	first = stack_from;
    i = 1;
    if(nbr_push > stack_from->content && nbr_push < ft_lstlast(stack_from)->content)
		i = 0;
	else if (nbr_push > biggest_finder(stack_from) || nbr_push < minimal_finder(stack_from))
		i = ft_find_index(stack_from , biggest_finder(stack_a));
	else
	{
		tmp = stack_from->next;
		while (stack_from->content < nbr_push || tmp->content > nbr_push)
		{
			stack_from = stack_from->next;
            tmp = tmp->next;
			i++;
		}
	}
	ft_lstclear(&first, free);

	return (i);
}
