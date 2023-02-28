/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:11:29 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 10:45:15 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *list)
{
	int				first_data;
	t_stack_node	*top_node;

	if (list->headnode && list->headnode->next)
	{
		first_data = list->headnode->data;
		top_node = list->top;
		top_node->next = list->headnode;
		list->headnode->prev = top_node;
		list->headnode = list->headnode->next;
		top_node->next->next = NULL;
		top_node->next->prev = NULL;
		list->top = top_node->next;
		top_node->next = NULL;
	}
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
