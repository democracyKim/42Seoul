/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:44:32 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/01 14:50:28 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *list)
{
	t_stack_node	*dummy;

	if (list == NULL || list->top == NULL)
	{
		ft_printf("empty list\n");
		return ;
	}
	dummy = list->top;
	ft_printf("\n-------display_stack---------\n");
	while (dummy != NULL)
	{
		ft_printf("| %d |\n", dummy->data);
		dummy = dummy->prev;
	}
	ft_printf("----------------------------\n");
}

int is_stack_sorted(t_stack *stack)
{
	t_stack_node	*below;
	int				data;

	if (stack == NULL || stack->headnode == NULL)
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
	ft_printf("Finish: stack is already sorted\n");
	return (1);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	if (stack == NULL)
		return (0);
	size = stack->size;
	return (size);
}