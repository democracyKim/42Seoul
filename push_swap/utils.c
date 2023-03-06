/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:44:32 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/06 15:34:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pattern_three_numbers(t_stack *stack)
{
	int		a;
	int		b;
	int		c;
	int		pattern;

	a = stack->top->data;
	b = stack->top->prev->data;
	c = stack->top->prev->prev->data;
	if (a > b && b > c && a > c)
		pattern = 1;
	else if (a > b && b < c && a > c)
		pattern = 2;
	else if (a < b && b > c && a > c)
		pattern = 3;
	else if (a < b && b > c && a < c)
		pattern = 4;
	else if (a > b && b < c && a < c)
		pattern = 5;
	else
		pattern = 6;
	return (pattern);
}
