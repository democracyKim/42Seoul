/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/06 14:47:55 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_depth(t_stack *stack)
{
    int	n;
	int	max_depth;
	
	n = stack_size(stack);
	max_depth = 0;
    while (n > 0)
	{
		n /= 3;
		max_depth++;
    }
    return (max_depth);
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
