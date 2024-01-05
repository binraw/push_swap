/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/05 15:01:15 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     biggest_finder(t_list *lst)
{
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
