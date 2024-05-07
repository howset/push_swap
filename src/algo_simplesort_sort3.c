/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simplesort_sort3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/07 17:23:05 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			min_idx(t_stack **stack, int val);
static void	exec_ops(t_stack *head, t_stack **stack_a, int minidx, 
				int next_minidx);

// sort_3 is just too long, more than 25 lines, so it is split to 3 functions. 
// but then it exceeds the number of functions in a file.
// so it is now put here. 
// do the sorting on stack_a
void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		minidx;
	int		next_minidx;

	head = *stack_a;
	minidx = min_idx(stack_a, -1);
	next_minidx = min_idx(stack_a, minidx);
	exec_ops(head, stack_a, minidx, next_minidx);
}

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
static void	exec_ops(t_stack *head, t_stack **stack_a, int minidx, 
				int next_minidx)
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
