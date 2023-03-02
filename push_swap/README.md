# Push_swap
### what to study
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://medium.com/@jamierobertdawson/

### Mandatory part
The game consists of 2 stacks, called a and b
  
Stack a : receives int numbers, no duplication  
Stack b : empty  

goal : sort numbers in ascending order into stack a  

### Functions
1. fill_stack.c

	### int check_duplicate(int data, int *array, int sign)
		- if array[data * sign] is 1, return (-1)
		- return (0);

	### int is_number(char *string)
		- see start to end of char string
			- If it's not a number, returns (-1);
			- the first digit of the string can be '-'.
		- return (0);
	
	### int is_int(long long data)
		- if data is an integer over int, return -1
		- else return 0

	### int valid_args(char *av, t_stack *stack_a)
		- variables : int data
		- static int array[INT_MAX]
		- if av is not NULL
			- is_number()
			- is_int()
		- use atoi, char * to long long int av
		- check_duplicate()
		- return data

	### int fill_stack(t_stack *stack_a, int argc, char **argv)
	- Put av in stack_A
	- if av[i] is not NULL and is a valid av
		- push(stack_A, data)

2. operations.c
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

3. merge_sort
### pivot
In the merge_sort algorithm, the pivot is a value selected as the median of the values in the original stack (stack_a). The purpose of selecting the pivot is to divide the original stack into two sub-stacks based on the pivot value. Values less than the pivot are moved to a temporary stack (stack_b), and the remaining values greater than or equal to the pivot remain in stack_a.

By repeatedly dividing the sub-stacks based on the median value, the algorithm is able to sort the original stack in ascending order.

static int get_median(t_stack *stack)
	- stack->array
	- sort array
	- get median

split_stack: The purpose of the split_stack function in the merge_sort algorithm is to divide the original stack (stack_a) into two sub-stacks based on a pivot value. Values less than the pivot are moved to a temporary stack (stack_b), and the remaining values greater than or equal to the pivot remain in stack_a. The pivot value is selected as the median of the values in the stack.

The split_stack function is called recursively in the merge_sort function, to further divide the sub-stacks into smaller sub-stacks until each sub-stack contains only one or two elements, which are sorted by calling the sort_three_number function.

After all sub-stacks have been sorted, they are merged back into a single stack by calling the merge_stacks function.

### merge_stacks
The purpose of the merge_stacks function in the merge_sort algorithm is to merge two sorted sub-stacks back into a single sorted stack.

In the merge_sort algorithm, the split_stack function divides the original stack (stack_a) into two sub-stacks based on a pivot value. Each sub-stack is recursively sorted using the merge_sort function until each sub-stack contains only one or two elements, which are sorted using the sort_three_number function.

After all sub-stacks have been sorted, the merge_stacks function is called to merge the sub-stacks back into a single sorted stack. The function compares the top elements of both stacks, and pushes the smaller element to the bottom of the merged stack. This process is repeated until both sub-stacks are empty, resulting in a single sorted stack.