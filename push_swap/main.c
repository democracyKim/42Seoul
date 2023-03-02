/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:14 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/02 12:21:36 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b)
		return (1);
	if (fill_stack(stack_a, argc, argv) == -1)
		return (1);
	if (is_stack_sorted(stack_a))
		destroy_stacks_and_exit(stack_a, stack_b, 0);
	push_swap(stack_a, stack_b);
	destroy_stacks_and_exit(stack_a, stack_b, 0);
	return (0);
}
