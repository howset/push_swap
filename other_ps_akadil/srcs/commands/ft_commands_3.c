/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/25 16:52:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <unistd.h>

void	ft_commands_rrr(t_stack *a, t_stack *b, int to_print)
{
	int	i;
	int	rotator;

	if (a->size > 1)
	{
		rotator = a->num[a->size - 1];
		i = a->size - 1 - 1;
		while (i > -1)
		{
			a->num[i + 1] = a->num[i];
			i--;
		}
		a->num[0] = rotator;
	}
	if (b->size > 1)
	{
		rotator = b->num[b->size - 1];
		i = b->size - 1;
		while (i-- > -1)
			b->num[i + 1] = b->num[i];
		b->num[0] = rotator;
	}
	if (to_print == 1)
		write(1, "rrr\n", 4);
}
