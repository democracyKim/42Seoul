/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/14 10:41:48 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_numbers(t_stack *stack_a)
{
	int	pattern;

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
		return ;
}

// static int	is_stack_sorted_a_from_index(t_stack *stack, size_t index)
// {
// 	t_stack_node	*below;
// 	int				data;

// 	if (stack == NULL || stack->head == NULL)
// 		return (TRUE);
// 	data = stack->top->data;
// 	below = stack->top->prev;
// 	while (below != NULL)
// 	{
// 		if (below->data < data)
// 			return (FALSE);
// 		data = below->data;
// 		below = below->prev;
// 	}
// 	return (TRUE);
// }

int	sort_a(t_stack *stack_a)
{
	size_t	size;

	size = stack_size(stack_a);
	if (size <= 1 || is_stack_sorted_a(stack_a))
		return (COMPLETE);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three_numbers(stack_a);
	// else if (size == 4)
	// {
		
	// }
	else
		return (CONTINUE);
	return (COMPLETE);
}
