/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part1.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/24 15:45:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PART1_H
# define FT_PART1_H

# include "ft_commands.h"
# include "ft_stack.h"
# include <stdlib.h>

int		ft_find_median(t_stack *a);
void	ft_sort_a(t_stack *a);
void	ft_quicksort(int *array, int l_pos, int r_pos);

#endif