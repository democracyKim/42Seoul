/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:28:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/03 14:48:54 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void split_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size = stack_size(stack_a);
	while (size > 0)
	{
		if (stack_top(stack_a) < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size--;
	}
}

static void split_stack_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size = stack_size(stack_a);
	while (size > 0)
	{
		if (stack_top(stack_a) >= pivot)
			pb(stack_a, stack_b);
		else
			rra(stack_a);
		size--;
	}
}

void merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
    while (!is_stack_empty(stack_b))
    {
        pa(stack_a, stack_b);
    }
}

static int flag_ba(t_stack *stack_a, t_stack *stack_b, int depth)
{
	int pivot;
	int max_depth;

	max_depth = stack_a->max_depth;
    if (stack_size(stack_a) <= 1 || is_stack_sorted_b(stack_a) || depth == max_depth)
        return (-1);
    else if (stack_size(stack_a) == 2)
    {
		sa(stack_a);
        return (-1);
    }
    else if (stack_size(stack_a) == 3)
    {
        sort_three_number_b(stack_a);
        return (-1);
    }
    pivot = get_median(stack_a);
    split_stack_b(stack_a, stack_b, pivot);
	return (0);
}

static int flag_ab(t_stack *stack_a, t_stack *stack_b, int depth)
{
	int pivot;
	int max_depth;

	max_depth = stack_a->max_depth;
    if (stack_size(stack_a) <= 1 || is_stack_sorted(stack_a) || depth == max_depth)
        return (-1);
    else if (stack_size(stack_a) == 2)
    {
        sa(stack_a);
        return (-1);
    }
    else if (stack_size(stack_a) == 3)
    {
        sort_three_number(stack_a);
        return (-1);
    }
	if (stack_size(stack_b) == 2)
	{
		if (stack_b->top->data < stack_b->top->prev->data)
			sb(stack_b);
	}
    else if (stack_size(stack_b) == 3)
    {
        sort_three_number_b(stack_b);
    }
    pivot = get_median(stack_a);
	ft_printf("pivot = %d\n", pivot);
    split_stack(stack_a, stack_b, pivot);
	return (0);
}

void merge_sort(t_stack *stack_a, t_stack *stack_b, int flag, int depth)
{
	int result;

	if (flag == AB)
		result = flag_ab(stack_a, stack_b, depth);
	else
		result = flag_ba(stack_a, stack_b, depth);
	if (result == -1)
		return ;
	display_two_stack(stack_a, stack_b);
	
	ft_printf("============ merge_sort--> AB, start\n");
    merge_sort(stack_a, stack_b, flag, depth + 1);

	ft_printf("============ merge_sort--> BA, start\n");
	flag *= -1;
    merge_sort(stack_b, stack_a, flag, depth + 1);

	ft_printf("============ merge_stacks, start\n");
	merge_stacks(stack_a, stack_b);
	display_two_stack(stack_a, stack_b);
}
