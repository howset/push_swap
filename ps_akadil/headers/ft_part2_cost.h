/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_cost.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/24 16:14:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PART2_COST_H
# define FT_PART2_COST_H

# include "ft_stack.h"

int	ft_cost_ra(t_stack *a, int value);
int	ft_cost_rra(t_stack *a, int value);
int	ft_cost_rb(t_stack *b, int value);
int	ft_cost_rrb(t_stack *b, int value);

#endif
