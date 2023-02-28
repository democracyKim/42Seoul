/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:11:29 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 10:45:13 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack *list)
{
	int				top_data;
	t_stack_node	*top_node;

	if (list->headnode && list->headnode->next)
	{
		top_data = list->top->data;
		top_node = list->top;
		list->top = top_node->prev;
		top_node->prev = list->top->prev;
		top_node->next = list->headnode;
		list->headnode->prev = top_node;
		list->top->prev = NULL;
		list->headnode = top_node;
		list->headnode->data = top_data;
	}
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
