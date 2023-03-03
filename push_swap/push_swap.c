/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/03 09:38:27 by minkim3          ###   ########.fr       */
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

int get_max_depth(int stack_size)
{
    if (stack_size <= 50)
        return 11;
    else if (stack_size <= 100)
        return 22;
    else if (stack_size <= 250)
        return 33;
    else
        return 44;
}

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	size_t size;

	size = stack_size(stack_a);
	if (size <= 1 || is_stack_sorted(stack_a))
		return ;
	else if (size == 2)
	{
		sa(stack_a);
		return ;
	}
	else if (size == 3)
	{
		sort_three_number(stack_a);
		return ;
	}
	merge_sort(stack_a, stack_b, AB);
}
