/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/24 15:45:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PART2_H
# define FT_PART2_H

# include "ft_stack.h"
# include <stdlib.h>

int		ft_find_cost(t_stack *a, t_stack *b, int ind);
void	ft_operate_with_cost(t_stack *a, t_stack *b, int ind);
void	ft_stabilizer(t_stack *a);

#endif