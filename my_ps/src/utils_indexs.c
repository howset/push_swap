/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_indexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:08:16 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/04/30 22:19:55 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lowest_val(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		flag;

	min = NULL;
	flag = 0;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (!flag || head->value < min->value))
		{
			min = head;
			flag = 1;
		}
		head = head->next;
	}
	return (min);
}

void	stack_indexing(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = lowest_val(stack);
	while (head)
	{
		head->index = index;
		index++;
		head = lowest_val(stack);
	}
}
