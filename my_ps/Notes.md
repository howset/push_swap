#Notes

## Organization
1. All files in ./src
2. Allowed operations are in 
## General
1. The `main` function in push_swap.c first checks for valid arguments by calling `ft_argcheck` in utils_checks.c. This function is responsible for splitting the input to args if necessary by using `ft_split` (from libft). Then it checks if the args are all numbers (`ft_isnbr`), if not, then error are printed by the function `ft_prt_err` in utils_free+print.c.