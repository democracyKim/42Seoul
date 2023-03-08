/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:12:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/08 12:54:26 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_empty(t_stack *stack)
{
	return (stack == NULL || stack->top == NULL);
}

int	is_stack_sorted_a(t_stack *stack)
{
	t_stack_node	*below;
	int				data;

	if (stack == NULL || stack->head == NULL)
		return (1);
	data = stack->top->data;
	below = stack->top->prev;
	while (below != NULL)
	{
		if (below->data < data)
			return (0);
		data = below->data;
		below = below->prev;
	}
	return (1);
}

int	is_stack_sorted_b(t_stack *stack)
{
	t_stack_node	*below;
	int				data;

	if (stack == NULL || stack->head == NULL)
		return (1);
	data = stack->top->data;
	below = stack->top->prev;
	while (below != NULL)
	{
		if (below->data > data)
			return (0);
		data = below->data;
		below = below->prev;
	}
	return (1);
}
