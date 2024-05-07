/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part1_median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:49:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_part1.h"

/*
    Goal:   Push everything (except 3 highest numbers) to stack 'b'
            using the median

    Why:    We are going to use bubblesort, so it is better to us if 
            stack 'b' will be somehow sorted so that we won't spend 
            extra commands to rotate the stack 'b'.

    How:    Sort the numbers locally and find the median. Then push 
            every number lower than median to stack 'b'. Repeat this
            process until 3 highest numbers left in stack. Then  
            sort last 3 elements. As a result, we will have sorted 'a', 
            and "kind of" sorted stack 'b' with higher numbers at the top
            So it will be cheaper to push the higher numbers.
*/

int	ft_part1_median(t_stack *a, t_stack *b)
{
	int	median;
	int	i;

	median = 0;
	while (a->size > 3)
	{
		median = ft_find_median(a);
		if (median == -1)
			return (0);
		i = 0;
		while (i < a->size)
		{
			if (a->num[0] < median)
				ft_commands_pb(a, b, 1);
			else
			{
				i++;
				ft_commands_ra(a, 1);
			}
		}
	}
	ft_sort_a(a);
	return (1);
}
