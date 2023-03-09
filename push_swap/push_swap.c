/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/09 14:22:52 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void first_split_stack(t_stack *stack_a, t_stack *stack_b)
{
	// 1. searching stack_a
	// and use if root big_pivot > stack_a->top->next->data
	// pb
	// 2. searching stack_b
	// and use if root small_pivot < stack_a->top->next->data
	// rb
	t_stack_node	*dummy;
	size_t			size;

	size = stack_a->size;
	dummy = stack_a->top;
	while (dummy != NULL && size)
	{
		if (stack_a->big_pivot >= dummy->data)
		{
			dummy = dummy->prev;
			pb(stack_a, stack_b);
			if (stack_b->top->data <= stack_a->small_pivot)
				rb(stack_b);
			size--;
		}
		else
		{
			dummy = dummy->prev;
			ra(stack_a);
			size--;
		}
		ft_printf("ok\n");
	}
	
	// 3. leaved stack_a's data push to stack_b
	// pb
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	get_pivot(stack_a);
	display_two_stack(stack_a, stack_b);
	first_split_stack(stack_a, stack_b);
	display_two_stack(stack_a, stack_b);
}
