/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free+print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:22:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/13 12:15:43 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free malloc-ed args
void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
}

// free stack
void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

// print error on fd 2, then exit
void	ft_prt_err(char **args, char *msg, int fd)
{
	free_args(args);
	ft_putendl_fd(msg, fd);
	exit(1);
}

/* void	ft_prt_err(char **args, char *msg, int fd)
{
	free_args(args);
	ft_putendl_fd(msg, fd);
	exit(1);
} */

// print linked List
// unused
/* void	print_list(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd(" ", 1);
		tmp = tmp->next;
	}
} */