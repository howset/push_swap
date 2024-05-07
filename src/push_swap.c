/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:44:54 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/03 21:45:53 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the main function is here

#include "push_swap.h"

void	stack_init(t_stack **stack, int argc, char **argv);
int		is_sorted(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// checks for valid inputs then initializes stack a
// preliminary check if stack is already sorted
// then call sort stack if not sorted
int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	ft_argcheck(argc, argv);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_init(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// initialize the stack
void	stack_init(t_stack **stack, int argc, char *argv[])
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lst_newnode(ft_atoi(args[i]));
		ft_lst_node2back(stack, new);
		i++;
	}
	stack_indexing(stack);
	if (argc == 2)
		free_args(args);
}

// checker if stack is already sorted or not
int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

// sort the stack, call corresponding algo
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_list_size(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

//#include<stdio.h>
/*
int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	
	//control for invalid inputs (no args, or no numbers)
	//make valid inputs to ints
	if (argc < 2)
		return(ft_printf("Invalid input.\n"));
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		//check argv for errors
	}
	
	//initialize stack(s)
	
	
	//int	i=0;
	//while (i<4)
	//{
	//	printf("Args[%d]:%s\n", i, argv[i]);
	//	i++;
	//} 
}*/