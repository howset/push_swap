/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_operation_seperated.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:32:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_commands.h"

void	ft_operation_ra_rb(t_stack *a, t_stack *b, int cost_ra, int cost_rb)
{
	while (cost_ra != 0 && cost_rb != 0)
	{
		ft_commands_rr(a, b, 1);
		cost_ra--;
		cost_rb--;
	}
	while (cost_ra != 0)
	{
		ft_commands_ra(a, 1);
		cost_ra--;
	}
	while (cost_rb != 0)
	{
		ft_commands_rb(b, 1);
		cost_rb--;
	}
	ft_commands_pa(a, b, 1);
}

void	ft_operation_ra_rrb(t_stack *a, t_stack *b, int cost_ra, int cost_rrb)
{
	while (cost_ra != 0)
	{
		ft_commands_ra(a, 1);
		cost_ra--;
	}
	while (cost_rrb != 0)
	{
		ft_commands_rrb(b, 1);
		cost_rrb--;
	}
	ft_commands_pa(a, b, 1);
}

void	ft_operation_rra_rb(t_stack *a, t_stack *b, int cost_rra, int cost_rb)
{
	while (cost_rra != 0)
	{
		ft_commands_rra(a, 1);
		cost_rra--;
	}
	while (cost_rb != 0)
	{
		ft_commands_rb(b, 1);
		cost_rb--;
	}
	ft_commands_pa(a, b, 1);
}

void	ft_operation_rra_rrb(t_stack *a, t_stack *b, int cost_rra, int cost_rrb)
{
	while (cost_rra != 0 && cost_rrb != 0)
	{
		ft_commands_rrr(a, b, 1);
		cost_rra--;
		cost_rrb--;
	}
	while (cost_rra != 0)
	{
		ft_commands_rra(a, 1);
		cost_rra--;
	}
	while (cost_rrb != 0)
	{
		ft_commands_rrb(b, 1);
		cost_rrb--;
	}
	ft_commands_pa(a, b, 1);
}
