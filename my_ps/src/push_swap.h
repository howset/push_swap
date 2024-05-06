/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:27:26 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/05/06 12:11:56 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h> //write
# include <limits.h> //intmax/min
# include <stdbool.h> //bool
# include "../lib/src/ft_printf/ft_printf.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include "../lib/src/libft/libft.h"

// ## typedef the struct
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// ## push_swap.c
void	stack_init(t_stack **stack, int argc, char **argv);
int		is_sorted(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// ## operations
// ### operations_swap.c
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

// ### operations_rotate.c
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

// ### operations_rotaterev.c
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// ### operations_push.c
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

// ## algo
// ### algo_simplesort.c
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
int		find_dist(t_stack **stack, int index);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// ### algo_simplesort_sort3.c
int		min_idx(t_stack **stack, int val);
void	exec_ops(t_stack *head, t_stack **stack_a, int minidx, int next_minidx);
void	sort_3(t_stack **stack_a);

// ### algo_radixsort.c
int		find_max_bits(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// ## utils
// ### utils_check.c
int		ft_isnbr(char *num);
int		ft_isduplicate(int num, char **argv, int i);
void	ft_argcheck(int argc, char **argv);

// ### utils_free+print.c
void	free_args(char **str);
void	free_stack(t_stack **stack);
void	ft_error(char *msg);
void	ft_prt_err(char *msg, int fd);
//void			print_list(t_stack *head);

// ### utils_index.c
t_stack	*find_minval(t_stack **stack);
void	stack_indexing(t_stack **stack);

// ### utils_list.c
t_stack	*ft_lst_newnode(int value);
t_stack	*ft_lst_pointer2last(t_stack *head);
void	ft_lst_node2back(t_stack **stack, t_stack *new);
int		ft_list_size(t_stack *head);

#endif