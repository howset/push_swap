# Push swap - A journey to find the most efficient sorting algorithm
> Push_swap is an algorithm project at school 42.

## Challenge

Sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations. You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments. <br />
<br />

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />
<br />


## The Project
Create two programs: ```checker``` and ```push_swap```. <br />

The ```checker``` program reads a random list of integers from the stdin, stores them, and checks to see
if they are sorted. <br />
<br />
The ```push_swap``` program calculates the moves to sort the integers – *pushing, popping, swapping* and *rotating* 
them between **stack a** and **stack b** – and displays those directions on the stdout. <br />
<br />
You can pipe ```push_swap``` into ```checker```, and ```checker``` will verify that ```push_swap```'s instructions were successful. 
<br />

Both programs must mandatorily parse input for errors, including empty strings, no parameters, 
non-numeric parameters, duplicates, and invalid/non-existent instructions.

**Push_Swap** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). <br />
Using normal ```libc``` functions is strictly forbidden. Students are however, allowed to use: ```write```, ```read```, ```malloc```, ```free```, ```exit```. 
It must not have any memory leaks. Errors must be handled carefully. <br />
In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).

</br></br>

## The Pseudo code

Generally, we are going to use the bubblesort algorithm. Firstly, we push everything to stack 'b' except 3 highest number and sort it. So we will have sorted stack "a". Then push numbers from 'b' for the correct place in 'a', so that it will keep sorted

My program is divided into 3 stages: (1) ```Parsing``` "ft_parse()", (2) pushing to stack 'b' by ```median method``` "ft_part1_median()", and then (3) pushing back to stack 'a' by ```calculating the cost``` of each number "ft_part2_cost()"

- ```Median method:```  Find the median of the stack and then push elements lower than median to b. Repeat until only 3 elements left in stack 'a'. As a result, the stack 'b' will be some kind of 'sorted' with higher numbers at the top. So it will be cheaper to push the higher number first
		
- ```Cost method:```    Calculate the numbers of moves needed to move each number from 'b' to 'a' and move the one with the lowest number of move. Repeat the last step until no numbers left in 'b'. 

## How to build:

Clone repo and type:

```Bash
$ make
```
Run `push_swap` program with array of ints as argument:

```Bash
$ ./push_swap 5 4 3 2 1
```

### Visualisation of execution big stack operation list example:

<img src="./visualizer.gif" width="500" alt="vizualize">

