/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simplesort_sort3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/02 15:05:45 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort_3 is just too long, more than 25 lines, so it is split to 3 functions. 
// but then it exceeds the number of functions in a file.
// so it is now put here along with some other helper functions. 

#include "push_swap.h"

// get the minimum index(sort_3)
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
void	exec_ops(t_stack **stack_a, t_stack *head, int minidx, int next_minidx)
{
	if (head->index == minidx && head->next->index != next_minidx)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_minidx)
	{
		if (head->next->index == minidx)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == minidx)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

// do the sorting
void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		minidx;
	int		next_minidx;

	head = *stack_a;
	minidx = min_idx(stack_a, -1);
	next_minidx = min_idx(stack_a, minidx);
	exec_ops(stack_a, head, minidx, next_minidx);
}

/* void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		minidx;
	int		next_minidx;

	head = *stack_a;
	calculate_idx(stack_a, &minidx, &next_minidx);
	if (head->index == minidx && head->next->index != next_minidx)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_minidx)
	{
		if (head->next->index == minidx)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == minidx)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
} */