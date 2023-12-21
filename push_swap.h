/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/21 11:46:20 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H


# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_list
{
	void			*content;
    struct s_list	*prev;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	is_empty_t_list(t_list li);
#endif