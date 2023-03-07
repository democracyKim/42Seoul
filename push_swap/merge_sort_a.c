/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:28:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/07 14:47:08 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_stack_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	size;
	int	size_stack;

	size = stack_size(stack_a);
	size_stack = size;
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

static int	merge_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	if (sort_a(stack_a) == COMPLETE)
		return (COMPLETE);
	sort_b(stack_b);
	pivot = get_median(stack_a);
	split_stack_a(stack_a, stack_b, pivot);
	return (CONTINUE);
}

void	merge_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = merge_a(stack_a, stack_b);
	if (result == COMPLETE)
		return ;
	merge_sort_a(stack_a, stack_b);
}
