/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:28:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/08 19:40:48 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	tmp;
	
	size = stack_a->size;
	stack_a->small_pivot = stack_min(stack_a, size / 2);
	stack_a->large_pivot = stack_max(stack_a, size / 2);
	while (size > 0)
	{
		tmp = stack_a->top->data;
		if (tmp >= stack_a->large_pivot)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			if (tmp < stack_a->small_pivot)
				rb(stack_b);
		}
	}
}
