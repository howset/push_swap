/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:28:05 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/30 18:13:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
	Goal:   Calculate and display on the standard output the smallest 
		program made of Push swap language instructions, that sorts the 
		integers received as arguments

	How:    My program is divided into 3 stages: Parsing "ft_parse()", 
		pushing to stack 'b' by median method "ft_part1_median()", and 
		then pushing back to stack 'a' by calculating the cost of each 
		number "ft_part2_cost()"

		Generally, we are going to use the bubblesort algorithm (read 
		it). We firstly push everything to stack 'b', and then push 
		some number from 'b' in the correct place in stack 'a'  

		Median method:  Find the median of the stack and then push 
			elements lower than median to b. Repeat until only 3 
			elements left in stack 'a'. As a result, the stack 'b' 
			will be some kind of 'sorted' with higher numbers at the 
			top. So it will be cheaper to push the higher number 
			first
		
		Cost method:    Calculate the number of operations(cost) needed 
			to push each number. Choose the lowest and push it in 
			correct place   

	input:  RDFM
	Output: RDFM
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		out_signal;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	out_signal = ft_init_stacks(&a, &b);
	if (out_signal == 0)
		return (ft_free_stacks_0(a, b));
	out_signal = ft_parse(argc, argv, a, b);
	if (out_signal == 0)
		return (ft_free_stacks_error_0(a, b));
	out_signal = ft_is_sorted(a);
	if (out_signal == 1)
		return (ft_free_stacks_0(a, b));
	out_signal = ft_part1_median(a, b);
	if (out_signal == 0)
		return (ft_free_stacks_0(a, b));
	out_signal = ft_part2_cost(a, b);
	if (out_signal == 0)
		return (ft_free_stacks_0(a, b));
	return (ft_free_stacks_0(a, b));
}
