/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:11:29 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/01 18:16:01 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack *list)
{
	t_stack_node	*head;
	t_stack_node	*top;

	if (list == NULL || list->headnode == NULL || list->headnode->next == NULL)
		return ;

	head = list->headnode;
	top = list->top;
	top->next = head;
	head->prev = top;

	list->top = head;
	list->headnode = head->next;
	list->top->next = NULL;
	list->headnode->prev = NULL;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	// ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	// ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	// ft_printf("rrr\n");
}
