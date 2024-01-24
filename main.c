/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:06:35 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/24 15:39:16 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    Stack_init(t_list **stack_a,char *value)
{
    char **str;
    int i;
    
    i = 0;
    if (!value)
        return ;
    str = ft_split(value, ' ');
    // printf("%s\n", value);
     while (str[i])
    {
        ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str[i])));
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
    size_t y;

    i = 0;
    y = 0;
    stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
    stack_a = NULL;
    stack_b = NULL;
    if (!argc)
        return (-1);
    if (argc < 2)
        return (-1);
    // printf("%s\n", "test");
   num = malloc(sizeof(char) * (argc));
    while (++i < argc) {
        if (ft_strlen(argv[i]) > 1 && i == 1) 
        {
            Stack_init(&stack_a,argv[i]);
        } 
        else
        {
            ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
        }
    }
    // printListe(stack_a);
    // pb_push(&stack_a,&stack_b);
    // pb_push(&stack_a,&stack_b);
    // printListe(stack_a);
    // printListe(stack_b);
    // ra_rotate(&stack_a);
    //  printListe(stack_a);
    if (ft_lstsize(stack_a) == 2)
    {
        if (stack_a->content > stack_a->next->content )
            sa_swap(&stack_a);
    }
    if (ft_lstsize(stack_a) == 3)
        sort_three_numbers(three_digit(stack_a), &stack_a);
    if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
        five_digit(&stack_a, &stack_b);
    if (ft_lstsize(stack_a) > 5)
        big_digit(&stack_a, &stack_b);

    // sa_swap(&stack_a);
    // printListe(stack_a);
    // pb_push(&stack_a,&stack_b);
    // pb_push(&stack_a,&stack_b);
    // sb_swap(&stack_b);
      printListe(stack_a);
    // printListe(stack_b);
    // ft_printf("%d\n",10);
}
