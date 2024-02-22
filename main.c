/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:06:35 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/22 12:58:11 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    Stack_init(t_list **stack_a,char *value)
{
    char **str;
    int i;
    long    n;
    
    i = 0;
    if (!value)
        return ;
    str = ft_split(value, ' ');
     while (str[i])
    {
        n = ft_atoi(str[i]);
        ft_lstadd_back(stack_a, ft_lstnew(n));
        i++;
    }
    free(str);
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
	int 	*num;
    int		i;
    long    n;

    i = 0;
    stack_a = NULL;
    stack_b = NULL;
    n = 0;
    if (!argc)
        return (-1);
    if (argc < 2)
        return (-1);
   num = malloc(sizeof(char) * (argc));
   if (!num)
   {
        ft_lstclear(&stack_a, free);
        ft_lstclear(&stack_b, free);
        return (0);
   }
   if (alpha_check(argv) == -1)
		return (-1);
    while (++i < argc) 
	{
        n = ft_atoi(argv[i]);
        if (n < INT_MIN || n > INT_MAX )
        {
                write_error(-1);
                ft_lstclear(&stack_a, free);
                ft_lstclear(&stack_b, free);
                return (0);
        }
        if (ft_strlen(argv[i]) > 1 && i == 1)
          Stack_init(&stack_a,argv[i]);
        else
            ft_lstadd_back(&stack_a, ft_lstnew((int)n));
    }
	if (write_error(check_dup(stack_a)) == -1)
    {
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    free(num);
        return (-1);
    }
		
	if (control_order(&stack_a) == 0)
    {
         ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    free(num);
        return (-1);
    }
        
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
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    
    free(num);
   
}
int control_order(t_list **stack_a)
{
    t_list *temp;
    t_list *dup;

    dup = ft_lstduplicate(*stack_a);
    temp = dup;
    while (temp->next != NULL) {
        if (temp->content > temp->next->content)
        {
            ft_lstclear(&dup, free);
            return (-1);
        }
        temp = temp->next;
    }
      ft_lstclear(&dup, free);
    return (0);
}
