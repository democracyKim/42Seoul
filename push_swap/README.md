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

	**int check_duplicate(int data, int *array, int sign)**
		- if array[data * sign] is 1, return (-1)
		- return (0);

	**int is_number(char *string)**
		- see start to end of char string
			- If it's not a number, returns (-1);
			- the first digit of the string can be '-'.
		- return (0);
	
	**int is_int(long long data)**
		- if data is an integer over int, return -1
		- else return 0

	**int valid_args(char *av, t_stack *stack_a)**
		- variables : int data
		- static int array[INT_MAX]
		- if av is not NULL
			- is_number()
			- is_int()
		- use atoi, char * to long long int av
		- check_duplicate()
		- return data

	**int fill_stack(t_stack *stack_a, int argc, char **argv)**
	- Put av in stack_A
	- if av[i] is not NULL and is a valid av
		- push(stack_A, data)

2. operations.c
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
