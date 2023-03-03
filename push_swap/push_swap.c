/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/03 16:48:38 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void sort_three_number_b(t_stack *stack_b)
{
	int a;
	int b;
	int c;

	a = stack_b->top->data;
	b = stack_b->top->prev->data;
	c = stack_b->top->prev->prev->data;
	if (a > b && b < c && a < c)
		rrb(stack_b);
	else if (a < b && b > c && a > c)
		sb(stack_b);
	else if (a > b && b < c && a > c)
	{
		rrb(stack_b);
		sb(stack_b);
	}
	else if (a < b && b < c && a < c)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	else if (a < b && b > c && a < c)
		rb(stack_b);
	else
		return ;
}

int max_depth(t_stack *stack)
{
    int n = stack_size(stack);
    int max_depth = 0;
    while (n > 0) {
        n >>= 1;
        max_depth++;
    }
    return (max_depth * 2);
}

void merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_stack_sorted(stack_a))
	{
		if (stack_a->top != NULL && stack_a->top->prev != NULL && stack_a->top->data < stack_a->top->prev->data)
			pb(stack_a, stack_b);
		sa(stack_a);
	}
    while (!is_stack_empty(stack_b))
    {
		while (stack_a->top->data < stack_b->top->data)
			ra(stack_a);
		pa(stack_a, stack_b);
		while (stack_a->top->data > stack_a->head->data)
		{
			if (stack_a->top != NULL && stack_a->top->prev != NULL && stack_a->top->data > stack_a->top->prev->data)
				sa(stack_a);
			rra(stack_a);
		}
    }
}

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->max_depth = max_depth(stack_a);
	stack_b->max_depth = stack_a->max_depth;
	merge_sort(stack_a, stack_b, AB, 0);
	ft_printf("<<<< ok >>>>\n");
	merge_stacks(stack_a, stack_b);
}
