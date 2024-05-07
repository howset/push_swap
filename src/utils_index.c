/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:08:16 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/07 17:16:41 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_minval(t_stack **stack);

// assign indexes to each node in the stack
void	stack_indexing(t_stack **stack)
{
	t_stack	*head;
	int		idx;

	idx = 0;
	head = find_minval(stack);
	while (head)
	{
		head->index = idx;
		idx++;
		head = find_minval(stack);
	}
}

// for stack_indexing. returns the node with the min value. 
static t_stack	*find_minval(t_stack **stack)
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
