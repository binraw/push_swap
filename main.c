/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:06:35 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/15 13:08:05 by rtruvelo         ###   ########.fr       */
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
    t_list  *stack_b;
     int *num;
    int i;
    int y;

    i = 0;
    y = 0;
    stack_a = NULL;
    stack_b = NULL;
    if (!argc)
        return (-1);
    if (argc < 2)
        return (-1);
    // printf("%s\n", "test");
   num = malloc(sizeof(int) * (argc -1));
    while (++i < argc) {
        if (ft_strlen(argv[i]) > 1 && i == 1) {
            Stack_init(argv[i], num);
            while (num[y])
            {
                ft_lstadd_back(&stack_a, ft_lstnew(num[y]));
                y++;
            }
        } 
        else {
            // ft_printf("%d\n", i);
            // num[i] = atoi(argv[i]);
            
            ft_lstadd_back(&stack_a, ft_lstnew(atoi(argv[i])));
            
         
        }
    }
    printListe(stack_a);
    if (ft_lstsize(stack_a) == 3)
        sort_three_numbers(three_digit(stack_a), &stack_a);
    if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
        five_digit(&stack_a, &stack_b);
    if (ft_lstsize(stack_a) > 5)
        big_digit(&stack_a, &stack_b);
    printListe(stack_a);
    // ft_printf("%d\n",10);
}
