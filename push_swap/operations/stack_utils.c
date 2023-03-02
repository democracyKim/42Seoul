/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:32:21 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/02 14:42:03 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	display_stack(t_stack *list)
{
	t_stack_node	*dummy;

	if (list == NULL || list->top == NULL)
	{
		ft_printf("empty list\n");
		ft_printf("-------------------------------------\n");
		return ;
	}
	dummy = list->top;
	ft_printf("-------display_stack---------\n");
	while (dummy != NULL)
	{
		ft_printf("| %d |\n", dummy->data);
		dummy = dummy->prev;
	}
	ft_printf("-------------------------------------\n");
}

void	display_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("stack_a ");
	display_stack(stack_a);
	ft_printf("stack_b ");
	display_stack(stack_b);
}

void	destroy_stack(t_stack **list)
{
	t_stack_node	*dummy;
	t_stack_node	*remove;

	if (!*list)
		return ;
	dummy = (*list)->head;
	while (dummy != NULL)
	{
		remove = dummy;
		dummy = dummy->next;
		free(remove);
		remove = NULL;
	}
	free(*list);
	*list = NULL;
	ft_printf("destroy complete\n");
}

int is_stack_sorted(t_stack *stack)
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
