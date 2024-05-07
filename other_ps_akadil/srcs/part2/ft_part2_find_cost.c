/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_find_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:32:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_part2_cost.h"

static int	ft_max(int num1, int num2);
static int	ft_find_most_optimal(int cost_ra, int cost_rb, int cost_rra,
				int cost_rrb);

/*
    Goal:   Find the cost of transfering the number to stack 'a'

    How:    Calculate the cost of rotating 'a', cost of reverse 
            rotating the 'a', then same with b. Then find the lowest
            between ra+rb, ra+rrb, rra+rb, rra+rrb
    
    input:  ind -   index of the element in stack 'b' to calculate
                    the cost
*/
int	ft_find_cost(t_stack *a, t_stack *b, int ind)
{
	int	cost_ra;
	int	cost_rb;
	int	cost_rra;
	int	cost_rrb;
	int	the_most_opt;

	cost_ra = ft_cost_ra(a, b->num[ind]);
	cost_rb = ft_cost_rb(b, b->num[ind]);
	cost_rra = ft_cost_rra(a, b->num[ind]);
	cost_rrb = ft_cost_rrb(b, b->num[ind]);
	the_most_opt = ft_find_most_optimal(cost_ra, cost_rb, cost_rra, cost_rrb);
	if (the_most_opt == 1)
		return (ft_max(cost_ra, cost_rb));
	else if (the_most_opt == 2)
		return (cost_ra + cost_rrb);
	else if (the_most_opt == 3)
		return (cost_rra + cost_rb);
	else
		return (ft_max(cost_rra, cost_rrb));
}

static int	ft_find_most_optimal(int cost_ra, int cost_rb, int cost_rra,
		int cost_rrb)
{
	int	cost_ra_rb;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	cost_rra_rrb;

	cost_ra_rb = ft_max(cost_ra, cost_rb);
	cost_ra_rrb = cost_ra + cost_rrb;
	cost_rra_rb = cost_rra + cost_rb;
	cost_rra_rrb = ft_max(cost_rra, cost_rrb);
	if (cost_ra_rb <= cost_ra_rrb && cost_ra_rb <= cost_rra_rb \
		&& cost_ra_rb <= cost_rra_rrb)
		return (1);
	else if (cost_ra_rrb <= cost_ra_rb && cost_ra_rrb <= cost_rra_rb \
			&& cost_ra_rrb <= cost_rra_rrb)
		return (2);
	else if (cost_rra_rb <= cost_ra_rb && cost_rra_rb <= cost_ra_rrb \
			&& cost_rra_rb <= cost_rra_rrb)
		return (3);
	else
		return (4);
}

static int	ft_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
