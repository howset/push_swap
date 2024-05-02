/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simplesort_sort3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/02 16:13:02 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort_3 is just too long, more than 25 lines, so it is split to 3 functions. 
// but then it exceeds the number of functions in a file.
// so it is now put here along with another helper function. 

#include "push_swap.h"

// get the node with the minimum index. returns only the index.
int	min_idx(t_stack **stack, int val)
{
	t_stack	*head;
	int		minidx;

	head = *stack;
	minidx = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < minidx) && head->index != val)
			minidx = head->index;
	}
	return (minidx);
}

// execute the operations in sort_3
void	exec_ops(t_stack *stack_a, int minidx, int next_minidx)
{
	if (stack_a->index == minidx && stack_a->next->index != next_minidx)
	{
		ra(&stack_a);
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (stack_a->index == next_minidx)
	{
		if (stack_a->next->index == minidx)
			sa(&stack_a);
		else
			rra(&stack_a);
	}
	else
	{
		if (stack_a->next->index == minidx)
			ra(&stack_a);
		else
		{
			sa(&stack_a);
			rra(&stack_a);
		}
	}
}

// do the sorting on stack_a
void	sort_3(t_stack **stack_a)
{
	int		minidx;
	int		next_minidx;

	minidx = min_idx(stack_a, -1);
	next_minidx = min_idx(stack_a, minidx);
	exec_ops(*stack_a, minidx, next_minidx);
}
