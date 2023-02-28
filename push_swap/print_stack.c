/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:58:21 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 14:14:45 by minkim3          ###   ########.fr       */
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
	dummy = list->headnode;
	ft_printf("\n-------display_list---------\n");
	while (dummy != NULL)
	{
		ft_printf("%d ", dummy->data);
		dummy = dummy->next;
	}
	ft_printf("\n----------------------------\n");
}
