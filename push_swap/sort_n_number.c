/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:09:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/01 18:59:50 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_pivot1(t_stack *stack, size_t size)
{
	t_stack_node *node;
	int pivot;
	size_t count = 0;

	node = stack->top;
	while (count < size / 3 && node != NULL)
	{
		count++;
		node = node->prev;
	}
	pivot = node->data;
	return pivot;
}

static int find_pivot2(t_stack *stack, size_t size)
{
	t_stack_node *node;
	int pivot;
	size_t count = 0;

	node = stack->top;
	while (count < 2 * size / 3 && node != NULL)
	{
		count++;
		node = node->prev;
	}
	pivot = node->data;
	return pivot;
}

static int	get_index(t_stack *stack, int value)
{
	t_stack_node	*node;
	int				index;

	index = 0;
	node = stack->top;
	while (node)
	{
		if (node->data == value)
			return (index);
		node = node->prev;
		index++;
	}
	return (-1);
}

static int	get_max(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	int max = stack->top->data;
	t_stack_node *node = stack->top;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->prev;
	}
	return (max);
}

static void push_max(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	if (stack_b->size == 0)
		return;
	max = get_max(stack_b);
	while (stack_b->top && stack_b->top->data != max)
	{
		if ((size_t)get_index(stack_b, max) > stack_b->size / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}

void sort_three_number(t_stack *stack_a)
{
	int a;
	int b;
	int c;

	a = stack_a->top->data;
	b = stack_a->top->prev->data;
	c = stack_a->top->prev->prev->data;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_large_number(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	int		pivot1;
	int		pivot2;

	size = stack_size(stack_a);
	pivot1 = find_pivot1(stack_a, size);
	pivot2 = find_pivot2(stack_a, size);
	ft_printf("pivot1 = %d\n", pivot1);
	ft_printf("pivot2 = %d\n", pivot2);
	quicksort(stack_a, stack_b, pivot1, pivot2);
	ft_printf("ok\n");
	while (stack_b->size > 0)
		push_max(stack_a, stack_b);
	sort_three_number(stack_a);
}
