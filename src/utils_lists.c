/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:04:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/07 17:24:22 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// creates a new node & return the pointer
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

// get the pointer of last node 
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

// add new node to the back (last) of the stack/list
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

// get the size of a list
int	ft_list_size(t_stack *begin_list)
{
	int	i;

	i = 1;
	if (begin_list == 0)
		return (0);
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
