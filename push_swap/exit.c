/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:07:58 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/01 14:44:29 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
