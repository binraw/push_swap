/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/03 11:13:29 by rtruvelo         ###   ########.fr       */
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
int	swap(t_list **stack);
#endif