/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:12:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:48:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <unistd.h>

void	ft_commands_ra(t_stack *a, int to_print)
{
	int	i;
	int	rotator;

	if (a->size < 2)
		return ;
	rotator = a->num[0];
	i = 1;
	while (i < a->size)
	{
		a->num[i - 1] = a->num[i];
		i++;
	}
	a->num[i - 1] = rotator;
	if (to_print == 1)
		write(1, "ra\n", 3);
}

void	ft_commands_rb(t_stack *b, int to_print)
{
	int	i;
	int	rotator;

	if (b->size < 2)
		return ;
	rotator = b->num[0];
	i = 1;
	while (i < b->size)
	{
		b->num[i - 1] = b->num[i];
		i++;
	}
	b->num[i - 1] = rotator;
	if (to_print == 1)
		write(1, "rb\n", 3);
}

void	ft_commands_rr(t_stack *a, t_stack *b, int to_print)
{
	int	i;
	int	rotator;

	if (a->size > 1)
	{
		rotator = a->num[0];
		i = 0;
		while (i++ < a->size)
			a->num[i - 1] = a->num[i];
		a->num[i - 2] = rotator;
	}
	if (b->size > 1)
	{
		rotator = b->num[0];
		i = 1;
		while (i < b->size)
		{
			b->num[i - 1] = b->num[i];
			i++;
		}
		b->num[i - 1] = rotator;
	}
	if (to_print == 1)
		write(1, "rr\n", 3);
}

void	ft_commands_rra(t_stack *a, int to_print)
{
	int	i;
	int	rotator;

	if (a->size < 2)
		return ;
	rotator = a->num[a->size - 1];
	i = a->size - 1 - 1;
	while (i > -1)
	{
		a->num[i + 1] = a->num[i];
		i--;
	}
	a->num[0] = rotator;
	if (to_print == 1)
		write(1, "rra\n", 4);
}

void	ft_commands_rrb(t_stack *b, int to_print)
{
	int	i;
	int	rotator;

	if (b->size < 2)
		return ;
	rotator = b->num[b->size - 1];
	i = b->size - 1 - 1;
	while (i > -1)
	{
		b->num[i + 1] = b->num[i];
		i--;
	}
	b->num[0] = rotator;
	if (to_print == 1)
		write(1, "rrb\n", 4);
}
