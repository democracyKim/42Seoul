/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:28:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/06 18:03:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void split_stack_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size = stack_size(stack_a);
	int size_stack = size;
	while (size > 0 && size_stack > 3)
	{
		if (stack_top(stack_a) < pivot)
		{
			pb(stack_a, stack_b);
			size_stack--;
		}
		else
			ra(stack_a);
		size--;
	}
	sort_a(stack_a);
}

static void split_stack_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size = stack_size(stack_a);
	int size_stack = size;
	while (size > 0 && size_stack > 3)
	{
		if (stack_top(stack_a) >= pivot)
		{
			pa(stack_b, stack_a);
			size_stack--;
		}
		else
			rrb(stack_a);
		size--;
	}
	sort_b(stack_b);
}

static int flag_ba(t_stack *stack_a, t_stack *stack_b, int depth)
{
	int pivot;
	int max_depth;

	max_depth = stack_b->max_depth;
	if (depth == max_depth || sort_b(stack_a) == COMPLETE)
		return (COMPLETE);
	sort_a(stack_b);
    pivot = get_median(stack_a);
    split_stack_b(stack_a, stack_b, pivot);
	return (0);
}

static int flag_ab(t_stack *stack_a, t_stack *stack_b, int depth)
{
	int pivot;
	int max_depth;

	max_depth = stack_a->max_depth;
	if (depth == max_depth || sort_a(stack_a) == COMPLETE)
		return (COMPLETE);
	sort_b(stack_b);
	pivot = get_median(stack_a);
    split_stack_a(stack_a, stack_b, pivot);
	return (0);
}

void merge_sort(t_stack *stack_a, t_stack *stack_b, int flag, int depth)
{
	int result;

	if (flag == AB)
		result = flag_ab(stack_a, stack_b, depth);
	else
		result = flag_ba(stack_a, stack_b, depth);
	if (result == COMPLETE)
		return ;
    merge_sort(stack_a, stack_b, flag, depth + 1);
	flag *= -1;
    merge_sort(stack_b, stack_a, flag, depth + 1);
}
