/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:24:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/31 13:02:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static int	ft_do_command_2(t_stack *a, t_stack *b, char *str);

int	ft_do_command(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 1)
		ft_commands_pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n") == 1)
		ft_commands_pb(a, b, 0);
	else if (ft_strcmp(str, "sa\n") == 1)
		ft_commands_sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 1)
		ft_commands_sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 1)
		ft_commands_ss(a, b, 0);
	else if (str && str[0] && str[0] == 'r')
		return (ft_do_command_2(a, b, str));
	else
		return (0);
	return (1);
}

static int	ft_do_command_2(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 1)
		ft_commands_ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 1)
		ft_commands_rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 1)
		ft_commands_rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 1)
		ft_commands_rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 1)
		ft_commands_rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 1)
		ft_commands_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_parse_the_commands(t_stack *a, t_stack *b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_do_command(a, b, str) == 0)
		{
			free (str);
			ft_error();
			return (0);
		}
		free (str);
		str = get_next_line(0);
	}
	return (1);
}
