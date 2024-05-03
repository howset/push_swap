/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:08:16 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/03 21:42:25 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_val(t_stack **stack);

// assign indexes to each node in the stack
void	stack_indexing(t_stack **stack)
{
	t_stack	*head;
	int		idx;

	idx = 0;
	head = min_val(stack);
	while (head)
	{
		head->index = idx;
		idx++;
		head = min_val(stack);
	}
}

// for stack_indexing. returns the node with the min value. 
t_stack	*min_val(t_stack **stack)
{
	t_stack	*head;
	t_stack	*minval_node;
	int		flag;

	minval_node = NULL;
	flag = 0;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (!flag || head->value < minval_node->value))
		{
			minval_node = head;
			flag = 1;
		}
		head = head->next;
	}
	return (minval_node);
}
