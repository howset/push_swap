/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotaterev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:42:43 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/07 17:14:07 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lst_pointer2last(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_list_size(*stack_a) < 2) || (ft_list_size(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
