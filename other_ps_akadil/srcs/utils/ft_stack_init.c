/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:25:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/30 18:14:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

int	ft_init_stacks(t_stack **a, t_stack **b)
{
	t_stack	*a_new;
	t_stack	*b_new;

	a_new = (t_stack *)malloc(sizeof(t_stack));
	if (!a_new)
		return (0);
	a_new->num = NULL;
	a_new->size = 0;
	*a = a_new;
	b_new = (t_stack *)malloc(sizeof(t_stack));
	if (!b_new)
		return (0);
	b_new->num = NULL;
	b_new->size = 0;
	*b = b_new;
	return (1);
}
