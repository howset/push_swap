/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_stabilizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:33:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_commands.h"

static int	ft_find_min(t_stack *stack);

/*
    Goal:   After we applied the cost method, our stack 'a'
            is in wrong shape. It is sorted, but the lowest is
            not at the top. So make it to the top
    
    How:    Just rotate or reverse rotate
*/
void	ft_stabilizer(t_stack *a)
{
	int	min;
	int	pos;
	int	i;

	min = ft_find_min(a);
	pos = 0;
	while (a->num[pos] != min)
		pos++;
	i = 0;
	if (pos < a->size - pos)
	{
		while (i < pos)
		{
			ft_commands_ra(a, 1);
			i++;
		}
		return ;
	}
	while (i < a->size - pos)
	{
		ft_commands_rra(a, 1);
		i++;
	}
}

static int	ft_find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = stack->num[0];
	while (i < stack->size)
	{
		if (stack->num[i] < min)
			min = stack->num[i];
		i++;
	}
	return (min);
}
