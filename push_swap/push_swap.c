/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/07 13:57:39 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_stack_sorted(stack_a))
	{
		if (stack_a->top != NULL && stack_a->top->prev != NULL && stack_a->top->data < stack_a->top->prev->data)
			pb(stack_a, stack_b);
		sa(stack_a);
	}
	display_two_stack(stack_a, stack_b);
    while (!is_stack_empty(stack_b))
    {
		while (stack_b->top != NULL && stack_b->top->prev != NULL && stack_b->top->data < stack_b->top->prev->data)
			sb(stack_b);
		pa(stack_a, stack_b);
		while (!is_stack_sorted(stack_a))
		{
			if (stack_a->top != NULL && stack_a->top->prev != NULL && stack_a->top->data < stack_a->top->prev->data)
				pb(stack_a, stack_b);
			sa(stack_a);
		}
    }
}

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	merge_sort_a(stack_a, stack_b);
	display_two_stack(stack_a, stack_b);
	merge_sort_b(stack_a, stack_b);
	display_two_stack(stack_a, stack_b);
	merge_stacks(stack_a, stack_b);
}
