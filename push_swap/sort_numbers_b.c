/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:39:50 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/06 14:40:12 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_number_b(t_stack *stack_b)
{
	int a;
	int b;
	int c;

	a = stack_b->top->data;
	b = stack_b->top->prev->data;
	c = stack_b->top->prev->prev->data;
	if (a > b && b < c && a < c)
		rrb(stack_b);
	else if (a < b && b > c && a > c)
		sb(stack_b);
	else if (a > b && b < c && a > c)
	{
		rrb(stack_b);
		sb(stack_b);
	}
	else if (a < b && b < c && a < c)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	else if (a < b && b > c && a < c)
		rb(stack_b);
	else
		return ;
}
