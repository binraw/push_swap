/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:44 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 14:34:56 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_t_list(t_list *li)
{
	if (li == NULL)
		return (1);

	return (0);
}
// int t_list_length(t_list li)
// {
// 	if (is_empty_t_list(li))
// 		return (0);
// 	return (li->lenght);
// }


// int	t_list_first(t_list li)
// {
// 	if (is_empty_t_list(li))
// 		return (0);
// 	return (li->begin->content);
// }

// int	t_list_last(t_list li)
// {
// 	if (is_empty_t_list(li))
// 		return (0);
// 	return (li->end->content);
// }


t_list *ft_lstduplicate(const t_list *original)
 {
    if (!original) 
        return NULL;
    

    t_list *copy = ft_lstnew(original->content);
    t_list *original_ptr = original->next;
    t_list *copy_ptr = copy;

    while (original_ptr) 
    {
        copy_ptr->next = ft_lstnew(original_ptr->content);
        copy_ptr = copy_ptr->next;
        original_ptr = original_ptr->next;
    }
    return copy;
}


void printListe(t_list *liste)
{
    if (liste == NULL)
    {
       ft_printf("NULL\n");
    }
    t_list *current = liste;
    while (current != NULL)
    {
        ft_printf("%d -> ", current->content);
        current = current->next;
    }
    ft_printf("NULL\n");
}
int ft_lstcontains(t_list *list, int value)
{
    while (list != NULL)
    {
        if (list->content == value)
            return 1; // La valeur est présente dans la liste
        list = list->next;
    }
    return 0; // La valeur n'est pas présente dans la liste
}

