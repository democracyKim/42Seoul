/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:28:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/02 15:00:26 by minkim3          ###   ########.fr       */
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

void merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
    while (!is_stack_empty(stack_b))
    {
        if (is_stack_empty(stack_a) || stack_top(stack_b) < stack_top(stack_a))
        {
            pa(stack_a, stack_b);
        }
        else if (stack_top(stack_a) > stack_top(stack_b))
        {
            if (stack_top(stack_a) < stack_bottom(stack_b))
            {
                pa(stack_a, stack_b);
            }
            else
            {
                ra(stack_a);
                continue;
            }
        }
        else
        {
            ra(stack_a);
            continue;
        }
    }
}

void merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	int pivot;

    if (stack_size(stack_a) <= 1)
        return;
    else if (stack_size(stack_a) == 2)
    {
        if (stack_top(stack_a) > stack_a->top->prev->data)
            sa(stack_a);
        return;
    }
    else if (stack_size(stack_a) == 3)
    {
        sort_three_number(stack_a);
        return;
    }
    pivot = get_median(stack_a);
	ft_printf("============ pivot = %d\n", pivot);
	
	ft_printf("============ split_stack, start\n");
    split_stack(stack_a, stack_b, pivot);
	display_two_stack(stack_a, stack_b);

	ft_printf("============ merge_sort--> AB, start\n");
    merge_sort(stack_a, stack_b);

	ft_printf("============ merge_sort--> BA, start\n");
    merge_sort(stack_b, stack_a);

	ft_printf("============ merge_stacks, start\n");
    merge_stacks(stack_a, stack_b);
	display_two_stack(stack_a, stack_b);
}
