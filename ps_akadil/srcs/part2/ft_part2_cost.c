/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:49:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_part2.h"

/*
    Goal:   Push the numbers back in the right place

    How:    Find the cost of each number in stack 'b'
            and push the one with the lowest cost. Repeat 
            until no elements left in the stack. Stabilize
            the stack 'a' at the end so that the lowest will
            be at the top
*/

int	ft_part2_cost(t_stack *a, t_stack *b)
{
	int	*costs;
	int	i;
	int	min_pos;

	while (b->size != 0)
	{
		min_pos = 0;
		costs = (int *)malloc(sizeof(int) * b->size);
		if (!costs)
			return (0);
		i = 0;
		while (i < b->size)
		{
			costs[i] = ft_find_cost(a, b, i);
			if (costs[i] < costs[min_pos])
				min_pos = i;
			i++;
		}
		ft_operate_with_cost(a, b, min_pos);
		free (costs);
	}
	ft_stabilizer(a);
	return (1);
}
