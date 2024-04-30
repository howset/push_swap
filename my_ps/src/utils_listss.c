/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_listss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:04:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/04/30 16:01:48 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer
t_stack	*ft_lst_newnode(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

// Adds the specified node to a stack (list) making it the head
void	ft_listadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the pointer of the last node 
t_stack	*ft_lst_pointer2last(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->next == NULL)
			return (ptr);
	}
	return (ptr);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_lst_node2back(t_stack **stack, t_stack *new_node)
{
	t_stack	*ptr;

	if (*stack)
	{
		ptr = ft_lst_pointer2last(*stack);
		ptr->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
}

// Returns the size of the linked List
int	ft_listsize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
