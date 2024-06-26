/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simplesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:54:23 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/07 17:13:06 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort_3 was originally here, but moved to another file because limitations

#include "push_swap.h"

static int		find_dist(t_stack **stack, int index);
static void		sort_4(t_stack **stack_a, t_stack **stack_b);
static void		sort_5(t_stack **stack_a, t_stack **stack_b);

// calls the corresponding algo if it's < 5 values. sort_3 is in another file.
void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (ft_list_size(*stack_a) == 0 || ft_list_size(*stack_a) == 1)
		return ;
	size = ft_list_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

// returns the distance (count) of a node with a given index from the top(first)
static int	find_dist(t_stack **stack, int index)
{
	t_stack	*head;
	int		dist;

	dist = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		dist++;
		head = head->next;
	}
	return (dist);
}

// get node with idx 0, then move it to top, then pb
// then sort the remaining 3 in stack_a
// then pa
static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	dist;

	dist = find_dist(stack_a, min_idx(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

// like sort_4
static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	dist;

	dist = find_dist(stack_a, min_idx(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dist == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
