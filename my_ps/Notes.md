#Notes

## Organization
1. All files in ./src
2. Allowed operations are in 
## General
1. The `main` function in push_swap.c first checks for valid arguments by calling `ft_argcheck` in utils_checks.c. This function is responsible for splitting the input to args if necessary by using `ft_split` (from libft). Then it checks if the args are all valid numbers (`ft_isnbr`), if not, then error are printed by the function `ft_prt_err` in utils_free+print.c. (how are duplicates dealt with?)
2. Then the <kbd>stacks a & b</kbd> are allocated by malloc. The stacks' structure are declared in the header file, which is a singly linked list that contains an index. <kbd>stack a</kbd> is initialized by the function `stack_init` in push_swap.c.
3. The declared variable <kbd>args</kbd> contains all the arguments. The loop adds the values to the declared stack <kbd>new</kbd> by calling the function ft_lstnew one at a time. The ft_lstnew function also assigns the index value at -1 and set the next pointer of the stack to NULL.