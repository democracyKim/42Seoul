#include "push_swap.h"

static void	cheapest_to_top_b(t_stack *stack_b, size_t number, int flag)
{
	while(number)
	{
		if (flag == RB)
			rb(stack_b);
		else
			rrb(stack_b);
		number--;
	}
}

static size_t	biggest_index(t_stack *stack)
{
	t_stack_node	*dummy;
	size_t			index;
	int				max;
	size_t			max_index;

	if (stack == NULL || stack->top == NULL)
		return (0);
	dummy = stack->top;
	max = 0;
	index = 0;
	max_index = 0;
	while (dummy)
	{
		if (dummy->data > max)
		{
			max = dummy->data;
			max_index = index;
		}
		dummy = dummy->prev;
		index++;
	}
	return (max_index);
}

static void	min_to_top(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	while (stack_a->head->data > stack_a->head->next->data)
		rra(stack_a);
	if (stack_a->top->data > stack_a->head->data)
		rra(stack_a);
}

static void	sort_stack_a(t_stack *stack_a, int number)
{
	t_stack_node	*dummy;

	if (stack_a == NULL || stack_a->top == NULL || sort_a(stack_a) == COMPLETE)
		return ;
	dummy = stack_a->top;
	if (is_biggest_num(stack_a, number) == TRUE)
	{
		min_to_top(stack_a);
		return ;
	}
	while (dummy && dummy->data < number)
	{
		dummy = dummy->prev;
		ra(stack_a);
		while (biggest_index(stack_a) + 1 != stack_size(stack_a)\
		&& stack_a->head && stack_a->head->data > number)
			rra(stack_a);
	}
	while (biggest_index(stack_a) + 1 != stack_size(stack_a)\
	&& stack_a->head && stack_a->head->data > number)
		rra(stack_a);
}

void	apply_greedy(t_stack *stack_a, t_stack *stack_b)
{
	size_t	index;

	index = 0;
	while (!is_stack_empty(stack_b))
	{
		sort_b(stack_b);
		index = get_min_cost_index(stack_a, stack_b);
		if (index * 2 <= stack_size(stack_b))
			cheapest_to_top_b(stack_b, index, RB);
		else
			cheapest_to_top_b(stack_b, stack_size(stack_b) - index, RRB);
		sort_stack_a(stack_a, stack_b->top->data);
		pa(stack_a, stack_b);
		if (is_biggest_num(stack_a, stack_a->top->data) == TRUE)
			ra(stack_a);
	}
	min_to_top(stack_a);
}
