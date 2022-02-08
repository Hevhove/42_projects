# Push Swap

## Project
The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
Your goal ? Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.

## Instructions

The game is composed of 2 stacks named a and b. • To start with:
* the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do
* nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do
* nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes
* the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## Approach
Several steps needed to be completed to ensure success in this project:
1. Argument checking
2. Sorting a small stack
3. Sorting a bigger stack

### Argument checking
In this step, we parse the inputs from `**argv` and eliminate any string input not between the interval 0-9 and inputs strings not starting with a number or minus. We also remove any duplicates after passing the inputs to ft_atoi. Finally, we can fill the stacks. We chose a linked list to represent the stack, as it allows us to quickly insert and remove elements from it. Make sure to check for inputs over the size of a 32-bit integer and return an Error if outside of this range.

```
typedef struct s_stack
{
	int				num;
	struct s_stack 	*next;
} t_stack;
```

### Sorting a small stack
To sort 3 numbers, we know the possible combinations of 3 numbers are of size 3! (factorial), giving us 3 * 2 * 1 combinations. One of these is already sorted. In our algorithm we simply devise the shortest operations to be completed for the remaining 5. For example for the list [1 3 2], we will need to perform operations `rra` and `sa`. for [2 1 3], we only need to `sa`. Given the two stacks s_a and s_b, we also provide the sort3 function with a communications list, where we will stringjoin a command to the back of the original string everytime we add a command. It's important to free remaining memory every time to avoid memory leaks after using our stringjoin function.

### Sorting a big stack
To sort stacks bigger than 3 numbers, I used the following algorithm:
1. Push all numbers in s_a to s_b except for 3.
2. Use the sort3 algorithm to sort s_a.
3. Create 2 "cost arrays": cost_a[len(s_b)] and cost_b[len(s_b)].
	- The cost_b array calculates for all elements currently in s_b, what is the cost to rotate this element to the top of s_b?
	- The cost_a array calculates for all elements currently in s_b, what is the cost to rotate the element in cost_a which is the closest to every element of s_b to the top of s_a.
	- An example: given 2 stacks a:[2 1 4] and b:[3 0 7], we calculate cost_b as [0 1 -1], where positive numbers stand for an upward rotation (ra/rb) while negatives are representing reverse rotations (rra/rrb). For cost_a, the calculation is a bit more complex: for elements [3 0 7], we need to check, which element in cost_a do we need to rotate to the top to push element [3] in the correct position? In this case, we need [4] to be on top, hence the the first element of cost_a is -1. Using the same logic for [0 7], we find cost_a to be [-1 1 1]
4. Once we have calculated all costs for s_b to be pushed into the correct position, we execute these operations, push to s_a and repeat for all elements. The program is working similar to a selection sort. Computation times are not optimized for speed (as this is of complexity Oˆ2), but for coming up with the optimal instructions for the stack operations. I'm using the this python visualizer to show the operations performed: [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer). I also created multiple scripts (test5.sh (credits to @pulgamecanica), test100.sh and test500.sh, to be executed in bash to check the performance of the algorithm)
