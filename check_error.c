/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:20:39 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/22 11:14:40 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content == tmp->content)
				return (-1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	free(tmp);
	return (0);
}

int write_error(int result)
{
    if (result == -1)
    {
        write(2, "Error\n", 7);
        return (-1);
    }
    return (0);
}
// static int	ft_isalpha(int c)
// {
// 	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
// 		|| (c == 44) || (c == 46) || (c == 47))
// 		return (1);
// 	return (0);
// }


int	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
            {
				write_error(-1);
                return (-1);
            }
			j++;
		}
		i++;
	}
    return (0);
}

int check_sorted(int nb)
{
	if (nb == 1)
		return (1);
	return (0);
}
