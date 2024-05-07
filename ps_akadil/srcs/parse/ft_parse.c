/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/26 16:40:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	ft_parse_normal(int argc, char **argv, t_stack *stack, int isS);
static int	ft_parse_string(char **argv, t_stack *stack);

/*
	Goal:	Parsing the passed arguments and assigning them to stacks

	How:	I've divided the function into 2: parsing normal arguments, and 
			parsing string argument. Then, at the end, create a 'b' stack

	input:	As said in their names
	output:	Signal. 1 if everything was ok, and 0 if something bad happened
*/
int	ft_parse(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
	{
		if (ft_parse_string(argv, a) == 0)
			return (0);
	}
	else
	{
		if (ft_parse_normal(argc, argv, a, 0) == 0)
			return (0);
	}
	if (ft_create_b(a->size, b) == 0)
		return (0);
	return (1);
}

/*
	Goal:	Parse the passed arguments

	How:	Firstly check if it is valid characters. Then go through each 
			argument and check it for if it is integer and if there any 
			duplicates
	
	input:	argc, argv, stack - are the same 
			isString -	made because I am going to use this function to parse
						the string too. So I need a variable to distinguish
	output:	signal 
*/
static int	ft_parse_normal(int argc, char **argv, t_stack *stack, int isS)
{
	int	*container;
	int	i;
	int	num;

	if (ft_check_normal(argv, 0) == 0)
		return (0);
	container = (int *)malloc(sizeof(int) * (argc - 1));
	if (!container)
		return (0);
	i = 0;
	while (argv[i + 1 - isS])
	{
		if (ft_check_for_int(argv[i + 1 - isS]) == 0)
			return (ft_free_arrayint_0(container));
		num = ft_atoi(argv[i + 1 - isS]);
		if (ft_check_for_duplicates(num, container, i) == 0)
			return (ft_free_arrayint_0(container));
		container[i++] = num;
	}
	stack->num = container;
	stack->size = argc - 1;
	return (1);
}

/*
	Goal:	Parse the string

	How:	Use ft_split function to seperate the string, then send the 
			output to normal parsing

			Also, free the new_argv, because we don't need it after parsing
*/
static int	ft_parse_string(char **argv, t_stack *stack)
{
	char	**new_argv;
	int		new_argc;

	new_argv = ft_split(argv[1], ' ');
	if (!new_argv)
		return (0);
	if (ft_check_normal(new_argv, 1) == 0)
		return (ft_free_2arraystr_0(new_argv));
	new_argc = ft_find_n_word(argv[1], ' ') + 1;
	if (ft_parse_normal(new_argc, new_argv, stack, 1) == 0)
		return (ft_free_2arraystr_0(new_argv));
	ft_free_2arraystr(new_argv);
	return (1);
}
