/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:50:26 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/07 11:12:14 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void split_stack_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size = stack_size(stack_b);
	int size_stack = size;
	while (size > 0 && size_stack > 3)
	{
		if (stack_top(stack_b) >= pivot)
		{
			pa(stack_a, stack_b);
			size_stack--;
		}
		else
			rrb(stack_b);
		size--;
	}
	sort_b(stack_b);
}

static int merge_b(t_stack *stack_a, t_stack *stack_b)
{
	int pivot;

	if (sort_b(stack_b) == COMPLETE)
		return (COMPLETE);
	sort_a(stack_a);
    pivot = get_median(stack_b);
    split_stack_b(stack_a, stack_b, pivot);
	return (CONTINUE);
}

void merge_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int result;

	result = merge_b(stack_a, stack_b);
	if (result == COMPLETE)
		return ;
    merge_sort_b(stack_a, stack_b);
}
