/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/06 16:04:11 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_numbers(t_stack *stack_a)
{
	int pattern;

	pattern = pattern_three_numbers(stack_a);
	if (pattern == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (pattern == 2)
		ra(stack_a);
	else if (pattern == 3)
		rra(stack_a);
	else if (pattern == 4)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (pattern == 5)
		sa(stack_a);
	else
		return;
}

void sort_four_numbers(t_stack *stack_a)
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

