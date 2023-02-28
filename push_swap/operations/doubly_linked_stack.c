/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:58:11 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 10:45:04 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*list;

	list = calloc(1, sizeof(t_stack));
	if (!list)
		return (NULL);
	return (list);
}

t_stack_node	*create_new_node(int data)
{
	t_stack_node	*new_node;

	new_node = calloc(1, sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

int	push(t_stack *list, int data)
{
	t_stack_node	*new_node;

	if (list == NULL)
		return (-1);
	new_node = create_new_node(data);
	if (list->headnode == NULL)
		list->headnode = new_node;
	else
	{
		list->top->next = new_node;
		new_node->prev = list->top;
	}
	list->top = new_node;
	return (0);
}

int	pop(t_stack *list)
{
	int				data;
	t_stack_node	*del_node;

	if (list == NULL || list->top == NULL)
		return (-1);
	data = list->top->data;
	del_node = list->top;
	if (list->top->prev == NULL)
	{
		list->top = NULL;
		list->headnode = NULL;
	}
	else
	{
		list->top = list->top->prev;
		list->top->next = NULL;
		del_node->prev = NULL;
	}
	free(del_node);
	del_node = NULL;
	return (data);
}

void	destroy_stack(t_stack **list)
{
	t_stack_node	*dummy;
	t_stack_node	*remove;

	if (!*list)
		return ;
	dummy = (*list)->headnode;
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
