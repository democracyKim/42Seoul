#include "push_swap.h"

static size_t	get_passing_cost(size_t index, size_t size)
{
	size_t	rb_count;
	size_t	rrb_count;

	rb_count = index;
	rrb_count = size - index;
	if (rb_count <= rrb_count)
		return (rb_count);
	else
		return (rrb_count);
}

static size_t	get_ra_count(t_stack *stack_a, t_stack_node *current_b_node)
{
	size_t			ra_count;
	size_t			pa_count;
	t_stack_node	*top_dummy;

	ra_count = 0;
	pa_count = 0;
	top_dummy = stack_a->top;
	ft_printf("point1");
	if (current_b_node->data < top_dummy->data)
	{
		ft_printf("point2");
		while (top_dummy > top_dummy->next)
		{
			ra_count++;
			top_dummy = top_dummy->prev;
		}
		pa_count++;
	}
	else if (current_b_node->data > top_dummy->data)
		pa_count++;
	return (ra_count + pa_count);
}

static size_t	get_sorting_cost(t_stack *stack_a, t_stack_node *current_b_node)
{
	size_t			ra_count;
	size_t			rra_count;

	ra_count = 0;
	rra_count = 0;
	ra_count = get_ra_count(stack_a, current_b_node);
	// rra_count = get_rra_count(stack_a, current_b_node);
	if (ra_count <= rra_count)
		return (ra_count);
	return (rra_count);
}

size_t	get_min_cost_index(t_stack *stack_a, t_stack *stack_b)
{
	size_t			current_cost;
	size_t			min_cost;
	size_t			current_b_index;
	size_t			min_cost_index;
	t_stack_node	*dummy;

	current_cost = 0;
	current_b_index = 0;
	dummy = stack_b->top;
	min_cost = SIZE_MAX;
	while (dummy)
	{
		current_cost += get_passing_cost(current_b_index, stack_b->size);
		current_cost += get_sorting_cost(stack_a, dummy);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			min_cost_index = current_b_index;
		}
		current_b_index++;
		dummy = dummy->prev;
	}
	return (min_cost_index);
}
