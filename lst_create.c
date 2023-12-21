/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:44 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/21 14:18:45 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_t_list(t_list li)
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





// void printListe(t_list *liste)
// {
//     if (liste == NULL)
//     {
//        ft_print("NULL\n");
//     }
//     t_list *current = liste->first;
//     while (current != NULL)
//     {
//         ft_print("%d -> ", current->content);
//         current = current->next;
//     }
//     ft_print("NULL\n");
// }
