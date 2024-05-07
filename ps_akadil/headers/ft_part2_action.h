/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_action.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/24 16:15:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PART2_ACTION_H
# define FT_PART2_ACTION_H

# include "ft_stack.h"

void	ft_operation_ra_rb(t_stack *a, t_stack *b, int cost_ra, int cost_rb);
void	ft_operation_ra_rrb(t_stack *a, t_stack *b, int cost_ra, int cost_rrb);
void	ft_operation_rra_rb(t_stack *a, t_stack *b, int cost_rra, int cost_rb);
void	ft_operation_rra_rrb(t_stack *a, t_stack *b, int cost_rra,
			int cost_rrb);

#endif
