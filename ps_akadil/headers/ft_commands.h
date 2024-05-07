/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:44:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 15:20:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMANDS_H
# define FT_COMMANDS_H

# include "ft_stack.h"

void	ft_commands_pa(t_stack *a, t_stack *b, int to_print);
void	ft_commands_pb(t_stack *a, t_stack *b, int to_print);
void	ft_commands_sa(t_stack *a, int to_print);
void	ft_commands_sb(t_stack *b, int to_print);
void	ft_commands_ss(t_stack *a, t_stack *b, int to_print);
void	ft_commands_ra(t_stack *a, int to_print);
void	ft_commands_rb(t_stack *b, int to_print);
void	ft_commands_rr(t_stack *a, t_stack *b, int to_print);
void	ft_commands_rra(t_stack *a, int to_print);
void	ft_commands_rrb(t_stack *b, int to_print);
void	ft_commands_rrr(t_stack *a, t_stack *b, int to_print);

#endif