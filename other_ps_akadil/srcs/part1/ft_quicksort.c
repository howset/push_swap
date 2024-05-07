/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:33:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/24 15:33:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Goal:       
        Sort the array with famous quicksort algorithm
    
    Why:
        The best algorithm for sorting, although according to results 
        the heapsort is much more efficient
        
                            (Quicksort, Heapsort)
        The best case:      O(n log(n)) O(n log(n))
        The average case:   O(n log(n)) O(n log(n))
        The worst case:     O(n^2)      O(n log(n))
        Memory usage:       O(log(n))   O(1)
    
    idea:
        Take random number "pivot" and place all lower numbers in the left
        and upper numbers in the right. The use recursion to left and right side
    
    Input:
        array: array of ints to sort
        l_pos: As I am going to use recursion, I need to specify the range
               of positions to sort
        r_pos: similar
    
    Output:
        Sorted array
*/
static void	ft_swap(int *a, int *b);

static int	ft_partition(int *array, int _l_pos, int _r_pos);

void	ft_quicksort(int *array, int l_pos, int r_pos)
{
	int	pi;

	if (l_pos < r_pos)
	{
		pi = ft_partition(array, l_pos, r_pos);
		ft_quicksort(array, l_pos, pi - 1);
		ft_quicksort(array, pi + 1, r_pos);
	}
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_partition(int *array, int _l_pos, int _r_pos)
{
	int	pivot;
	int	i;
	int	j;

	i = _l_pos;
	pivot = array[_r_pos];
	j = _l_pos;
	while (j < _r_pos)
	{
		if (array[j] <= pivot)
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[j]);
	return (i);
}
