/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_find_cost_seperated.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:32:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:49:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_part2.h"

static int	ft_find_min(t_stack *stack);

int	ft_cost_ra(t_stack *a, int value)
{
	int	min;
	int	ptr1;
	int	ptr2;

	min = ft_find_min(a);
	ptr1 = 0;
	if (min > value)
	{
		while (a->num[ptr1] != min)
			ptr1++;
	}
	else
	{
		ptr2 = a->size - 1;
		while (a->num[ptr1] < value || value < a->num[ptr2])
		{
			ptr1++;
			ptr2++;
			if (ptr2 == a->size)
				ptr2 = 0;
		}
	}
	return (ptr1);
}

int	ft_cost_rra(t_stack *a, int value)
{
	int	min;
	int	ptr1;
	int	ptr2;

	ptr1 = a->size - 1;
	min = ft_find_min(a);
	if (min > value)
	{
		while (a->num[ptr1] != min)
			ptr1--;
		ptr1--;
	}
	else
	{
		ptr2 = 0;
		while (a->num[ptr2] < value || value < a->num[ptr1])
		{
			ptr1--;
			ptr2--;
			if (ptr2 == -1)
				ptr2 = a->size - 1;
		}
	}
	return (a->size - 1 - ptr1);
}

int	ft_cost_rb(t_stack *b, int value)
{
	int	ptr;

	ptr = 0;
	while (b->num[ptr] != value)
		ptr++;
	return (ptr);
}

int	ft_cost_rrb(t_stack *b, int value)
{
	int	ptr;

	ptr = b->size - 1;
	while (b->num[ptr] != value)
		ptr--;
	return (b->size - ptr);
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
