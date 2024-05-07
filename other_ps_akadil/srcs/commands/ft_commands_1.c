/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:30:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:48:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <unistd.h>

void	ft_commands_pa(t_stack *a, t_stack *b, int to_print)
{
	int	pusher;
	int	i;

	if (b->size == 0)
		return ;
	pusher = b->num[0];
	i = 1;
	while (i < b->size)
	{
		b->num[i - 1] = b->num[i];
		i++;
	}
	b->size = b->size - 1;
	i = a->size - 1;
	while (i > -1)
	{
		a->num[i + 1] = a->num[i];
		i--;
	}
	a->num[0] = pusher;
	a->size = a->size + 1;
	if (to_print == 1)
		write(1, "pa\n", 3);
}

void	ft_commands_pb(t_stack *a, t_stack *b, int to_print)
{
	int	pusher;
	int	i;

	if (a->size == 0)
		return ;
	pusher = a->num[0];
	i = 1;
	while (i < a->size)
	{
		a->num[i - 1] = a->num[i];
		i++;
	}
	a->size = a->size - 1;
	i = b->size - 1;
	while (i > -1)
	{
		b->num[i + 1] = b->num[i];
		i--;
	}
	b->num[0] = pusher;
	b->size = b->size + 1;
	if (to_print == 1)
		write(1, "pb\n", 3);
}

void	ft_commands_sa(t_stack *a, int to_print)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->num[0];
	a->num[0] = a->num[1];
	a->num[1] = temp;
	if (to_print == 1)
		write(1, "sa\n", 3);
}

void	ft_commands_sb(t_stack *b, int to_print)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->num[0];
	b->num[0] = b->num[1];
	b->num[1] = temp;
	if (to_print == 1)
		write(1, "sb\n", 3);
}

void	ft_commands_ss(t_stack *a, t_stack *b, int to_print)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->num[0];
		a->num[0] = a->num[1];
		a->num[1] = temp;
	}
	if (b->size > 1)
	{
		temp = b->num[0];
		b->num[0] = b->num[1];
		b->num[1] = temp;
	}
	if (to_print == 1)
		write(1, "ss\n", 3);
}
