/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/15 15:11:47 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H


# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "/printf/libft/libft.h"
# include "/printf/printf.h"

typedef struct s_list_node
{
	int			*content;
    struct s_list	*prev;
	struct s_list	*next;
}	t_list_node;

typedef struct s_list
{
	int     lenght;
    struct s_list_node	*begin;
	struct s_list_node	*end;
}	*t_list;


t_list push_front_t_list(t_list li, int x);
t_list push_back_t_list(t_list li, int x);
int	t_list_first(t_list li);
int	t_list_last(t_list li);
int t_list_length(t_list li);
int	is_empty_t_list(t_list li);
#endif