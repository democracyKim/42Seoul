/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:07:58 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 19:09:28 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_stack_node	*node;

	if (stack == NULL || stack->headnode == NULL)
		return (1);
	node = stack->headnode;
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	ft_printf("Finish: stack is already sorted\n");
	return (1);
}

void	destroy_stacks_and_exit(t_stack *stack_a, \
		t_stack *stack_b, int exit_status)
{
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	exit(exit_status);
}

void	error_exit(char *message, t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error: %s\n", message);
	if (stack_a)
		destroy_stack(&stack_a);
	if (stack_b)
		destroy_stack(&stack_b);
	exit(EXIT_FAILURE);
}
