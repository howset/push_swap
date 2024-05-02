#Notes

## Organization
1. All files in ./src
2. Allowed operations are in 

## General
### Main and Stack Initialization
1. ▶️main & ft_argcheck◀️ The `main` function in push_swap.c first checks for valid arguments by calling `ft_argcheck` in utils_checks.c. This function is responsible for splitting the input to args if necessary by using `ft_split` (from libft). Then it checks if the args are all valid numbers (`ft_isnbr`), if not, then error are printed by the function `ft_prt_err` in utils_free+print.c. Duplicates are checked with `ft_isdupli`. If `ft_split` is utilized, then due to memory allocation, <kbd>args</kbd> has to be freed.
2. ▶️main◀️ Then the <kbd>stacks a & b</kbd> are allocated by malloc. The stacks' structure are declared in the header file, which is a singly linked list that contains an <kbd>index</kbd> (to determine the most efficient sequence of operations to sort the stack - e.g., if an element is far from its correct position in the sorted stack (i.e., its index is far from its value), it might be more efficient to use a series of rotates or reverse rotates to move it to its correct position, rather than using a series of pushes and swaps.), a <kbd>value</kbd>, and a <kbd>pointer</kbd> to the next node. <kbd>stack a</kbd> is initialized by the function `stack_init` in push_swap.c.
3. ▶️stack_init◀️ The declared variable <kbd>args</kbd> contains all the arguments. The loop creates a new node by calling the function `ft_lst_newnode` (in utils_list.c) and adds it to the back of the stack by the using the function `ft_lst_nodeback`.
	- The `ft_lst_newnode` function adds the value to the newly created node, assigns the <kbd>index</kbd> value at -1 (sentinel value, real value will be set by the function `stack_indexing`) and set the <kbd>next</kbd> pointer of the stack to NULL. The `ft_lst_node2back` checks if the stack is empty or not. If it is empty, it makes the <kbd>new_node</kbd> as the first node. If it is not empty, then it calls the `ft_lst_pointer2last` to get the pointer to the last node in the stack. Then the `ft_lst_node2back` sets the <kbd>next</kbd> field of the last node in the stack to the <kbd>new_node</kbd>, and the <kbd>next</kbd> field of the <kbd>new_node</kbd> to NULL.
4. ▶️stack_indexing◀️ Then after the stack has been populated by the values, the function `stack_indexing` (in utils_index.c) assigns the proper indexes. This function relies on the function `lowest_val` which finds the node with the smallest value in a stack that has not been indexed. The `lowest_val` function loops to check each node. If the <kbd>index</kbd> of a node is -1 and do not have the <kbd>flag</kbd>, then it is at position 1. The flag is then set to 1 and updates <kbd>min</kbd> to the current node. The next node is then checked if not yet indexed (-1), and checked if the <kbd>value</kbd> is less then the previous node. After the loop, the function returns the min pointer, which points to the node with the minimum value.
Basically, if the array is {3, 1, 2, 4}, the index would be 2, 0, 1, 3, respectively.
5. ▶️main◀️ Then after the stack (linked list) is created, the main function makes a preliminary check (`already_sorted`) if the <kbd>values</kbd> are already sorted, if yes return zero and free the `stacks a & b`. If not, then it calls the function `sort_stack`.
6. ▶️sort_stack◀️ The `sort_stack` function checks the size of <kbd>stack a</kbd> (by `ft_list_size`) and calls the corresponding sorting algo. If size < 5, then use the hardcoded `simple_sort`, if more, then `radix_sort` (both in its respective algo_*.c files).

### Algorithms
#### Simple sort
1. ▶️simple_sort◀️ For values amounting up to 5, the algo is hardcoded in this simple_sort algo.
2. ▶️simple_sort◀️ The first thing done here is a control sequence to check if the input values (or the values in the stack) are already sorted, or there is either no value given or just one value. If any of these is true, then nothing is returned. If not, then proceed to get the size of the stack/length of the value array. The consequent steps depends on the size.
	- If there are only 2 values, then there is only one operation to be done, namely swapping the values using `sa`.
	- If size is 3 or more, then go to the corresponding functions.
3. ▶️sort_3◀️ To sort 3, `stack b` is not used. This function sorts a stack of three elements by performing rotate, swap, and reverse rotate operations based on the relative values of the index of the head and the next node in the stack.
4. ▶️sort_4◀️ 

#### Radix sort

### Operations
#### Push
#### Swap
#### Rotate
#### Reverse rotate

### Utilities
