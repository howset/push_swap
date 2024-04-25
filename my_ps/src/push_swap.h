/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:27:26 by hsetyamu          #+#    #+#             */
/*   Updated: 2024/04/25 19:49:17 by hsetyamu         ###   ########.fr       */
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
static void	stack_init(t_stack **stack, int argc, char **argv);
static void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// ## operations
// ### operations_swap.c
int	swap(t_stack **stack);
int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack **stack_a, t_stack **stack_b);

// ### operations_rotate.c
int	rotate(t_stack **stack);
int	ra(t_stack **stack_a);
int	rb(t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);

// ### operations_rotaterev.c
int	reverse_rotate(t_stack **stack);
int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);

// ### operations_push.c
int	push(t_stack **stack_to, t_stack **stack_from);
int	pa(t_stack **stack_a, t_stack **stack_b);
int	pb(t_stack **stack_a, t_stack **stack_b);

// ## algo
// ### algo_simplesort.c
static int	get_min(t_stack **stack, int val);
static void	sort_3(t_stack **stack_a);
static void	sort_4(t_stack **stack_a, t_stack **stack_b);
static void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

// ### algo_radixsort.c
static int	get_max_bits(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// ## utils
// ### utils_check.c
static int	ft_contains(int num, char **argv, int i);
static int	ft_isnum(char *num);
void	ft_check_args(int argc, char **argv);

// ### utils_free+print.c
void	ft_free(char **str);
void	free_stack(t_stack **stack);
void	ft_error(char *msg);
//void	printList(t_stack *head);

// ### utils_index.c
static t_stack	*get_next_min(t_stack **stack);
void	index_stack(t_stack **stack);

// ### utils_list.c
t_stack	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int	ft_lstsize(t_stack *head);

// ### utils_others.c
int	is_sorted(t_stack **stack);
int	get_distance(t_stack **stack, int index);
void	make_top(t_stack **stack, int distance);

#endif