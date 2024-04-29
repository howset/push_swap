/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:07:20 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/04/29 19:02:47 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	make_top(t_stack **stack, int distance)
{
	t_stack	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_listsize(head) - distance;
	if (distance <= (ft_listsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}
