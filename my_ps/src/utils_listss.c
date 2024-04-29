/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_listss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:04:37 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:12 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer
t_stack	*ft_listnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_listadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the pointer of the last node 
t_stack	*ft_listlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_listadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_listlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
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
