#include "push_swap.h"

void	apply_greedy(t_stack *stack_a, t_stack *stack_b)
{
	
	size_t	min_cost_index;

	while (!is_stack_empty(stack_b))
	{
		min_cost_index = get_min_cost_index(stack_a, stack_b);
		// ft_printf("min_cost_index : %u \n", min_cost_index);
		// apply_sorting();
	}
}