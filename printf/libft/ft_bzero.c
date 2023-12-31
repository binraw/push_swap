/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:29 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/11/22 17:29:30 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char		*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
