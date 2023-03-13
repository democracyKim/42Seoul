#include "push_swap.h"

static void	min_to_top_b(t_stack *stack_b, size_t number, int flag)
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

int	num_is_biggest(t_stack *stack_a, int number)
{
	t_stack_node	*dummy;

	dummy = stack_a->top;
	while (dummy)
	{
		if (dummy->data > number)
			return (FALSE);
		dummy = dummy->prev;
	}
	return (TRUE);
}

static void	sort_stack_a(t_stack *stack_a, int number)
{
	t_stack_node	*dummy;
	t_stack_node	*tmp;

	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	dummy = stack_a->top;
	if (num_is_biggest(stack_a, number) == TRUE)
		return ;
	while (dummy && dummy->data < number)
	{
		dummy = dummy->prev;
		ra(stack_a);
		tmp = stack_a->head;
		while (tmp && tmp->data > number)
		{
			rra(stack_a);
			tmp = stack_a->head;
		}
	}
}

static void	min_to_top(t_stack *stack_a)
{
	while (stack_a->head->data > stack_a->head->next->data)
		rra(stack_a);
	if (stack_a->top->data > stack_a->head->data)
		rra(stack_a);
}

void	apply_greedy(t_stack *stack_a, t_stack *stack_b)
{
	size_t	index;

	index = 0;
	while (!is_stack_empty(stack_b))
	{
		index = get_min_cost_index(stack_a, stack_b);
		if (index * 2 <= stack_size(stack_b))
			min_to_top_b(stack_b, index, RB);
		else
			min_to_top_b(stack_b, stack_size(stack_b) - index, RRB);
		sort_stack_a(stack_a, stack_b->top->data);
		pa(stack_a, stack_b);
		if (stack_a->top->prev->data < stack_a->top->data \
		&& stack_a->head->data < stack_a->top->data)
			ra(stack_a);
	}
	min_to_top(stack_a);
}