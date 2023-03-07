/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:39:50 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/07 14:54:09 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_numbers_b(t_stack *stack_b)
{
	int	pattern;

	pattern = pattern_three_numbers(stack_b);
	if (pattern == 6)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	if (pattern == 5)
		rrb(stack_b);
	else if (pattern == 4)
		rb(stack_b);
	else if (pattern == 3)
		sb(stack_b);
	else if (pattern == 2)
	{
		rrb(stack_b);
		sb(stack_b);
	}
	else
		return ;
}

int	sort_b(t_stack *stack_b)
{
	if (stack_size(stack_b) <= 1 || is_stack_sorted_b(stack_b))
		return (COMPLETE);
	else if (stack_size(stack_b) == 2)
		sb(stack_b);
	else if (stack_size(stack_b) == 3)
		sort_three_numbers_b(stack_b);
	else
		return (CONTINUE);
	return (COMPLETE);
}
