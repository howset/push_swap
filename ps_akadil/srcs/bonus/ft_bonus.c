/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:24:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/31 12:22:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ft_init_stacks(&a, &b) == 0 || argc < 2 || argv[1] == (void *)0)
		return (ft_free_stacks_0(a, b));
	if (ft_parse(argc, argv, a, b) == 0)
		return (ft_free_stacks_error_0(a, b));
	if (ft_parse_the_commands(a, b) == 0)
		return (ft_free_stacks_0(a, b));
	if (ft_is_sorted(a) == 1 && ft_is_empty(b) == 1)
		return (ft_result_free_return(a, b, 1));
	return (ft_result_free_return(a, b, 0));
}
