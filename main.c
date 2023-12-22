/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:06:35 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/22 13:39:57 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    Stack_init(char *value, int *num)
{
    char **str;
    int i;
    
    i = 0;
    if (!value)
        return ;
    str = ft_split(value, ' ');
     while (str[i])
    {
        num[i] = ft_atoi(str[i]);
        i++;
    }
    free(str);
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    int *num;
    int i;

    i = 0;
    stack_a = NULL;
    // if (!argc)
    //     return (-1);
    // if (argc < 2)
        // return (-1);
    printf("%s\n", "test");
   num = malloc(sizeof(int) * (argc - 1));
    while (++i < argc) {
        if (ft_strlen(argv[i]) > 1) {
            Stack_init(argv[i], num);
            ft_lstadd_back(&stack_a, ft_lstnew(num[i - 1]));  // affiche seulement le premier rajouter une boucle
        } 
        else {
            num[i] = atoi(argv[i]);
            ft_lstadd_back(&stack_a, ft_lstnew(num[i]));
         
        }
    }
    printListe(stack_a);
}