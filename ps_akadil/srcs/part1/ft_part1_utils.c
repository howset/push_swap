/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part1_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:32:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/29 17:02:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_part1.h"
#include <stdlib.h>

static int	*ft_int_array_copy(int *array, int size);

/*
    Goal:   Find the median

    How:    Sort the numbers by quicksort locally, then take
            the middle number as a median

    Variables:
            array_from_stack -  the array from stack 
            median_ind -        Index of the median number
            returner -          Median number
*/
int	ft_find_median(t_stack *a)
{
	int	*array_from_stack;
	int	returner;
	int	median_ind;

	array_from_stack = ft_int_array_copy(a->num, a->size);
	if (!array_from_stack)
		return (-1);
	ft_quicksort(array_from_stack, 0, a->size - 1);
	median_ind = (int)(a->size / 2);
	returner = array_from_stack[median_ind];
	free(array_from_stack);
	return (returner);
}

/*
    Goal:   Sort stack a

    How:    Take the highest number and rotate it so that it will
            be at the bottom. If stack is sorted, then ok, if no, 
            just swap the top values
*/
void	ft_sort_a(t_stack *a)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2 && a->num[0] < a->num[1])
		return ;
	else if (a->size == 2 && a->num[0] > a->num[1])
		ft_commands_sa(a, 1);
	else
	{
		if (a->num[0] > a->num[1] && a->num[0] > a->num[2])
			ft_commands_ra(a, 1);
		else if (a->num[1] > a->num[0] && a->num[1] > a->num[2])
			ft_commands_rra(a, 1);
		if (a->num[0] > a->num[1])
			ft_commands_sa(a, 1);
	}
}

static int	*ft_int_array_copy(int *array, int size)
{
	int	*new_array;
	int	i;

	new_array = (int *)malloc(sizeof(int) * size);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}
	return (new_array);
}
