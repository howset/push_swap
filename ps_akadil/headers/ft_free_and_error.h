/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/31 12:55:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_AND_ERROR_H
# define FT_FREE_AND_ERROR_H

# include "ft_stack.h"

int		ft_free_stacks_error_0(t_stack *a, t_stack *b);
int		ft_free_stacks_0(t_stack *a, t_stack *b);
void	ft_free_stacks(t_stack *a, t_stack *b);
void ft_free_stacks_error(t_stack *a, t_stack *b);
int		ft_free_2arraystr_error_0(char **trash);
int		ft_free_2arraystr_0(char **trash);
void	ft_free_2arraystr(char **trash);
int		ft_free_arrayint_0(int *trash);
int		ft_free_str_0(char *str);
void	ft_error(void);


#endif
