/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/07 11:12:39 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three_numbers(t_stack *stack_a)
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

// void sort_four_numbers(t_stack *stack_a)
// {
// 	int pattern;

// 	pattern = pattern_four_numbers(stack_a);
	
// }


int	sort_a(t_stack *stack_a)
{
    if (stack_size(stack_a) <= 1 || is_stack_sorted_b(stack_a))
        return (COMPLETE);
    else if (stack_size(stack_a) == 2)
		sa(stack_a);
    else if (stack_size(stack_a) == 3)
        sort_three_numbers(stack_a);
	else
		return (CONTINUE);
	return (COMPLETE);
}
