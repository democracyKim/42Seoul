/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:14 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 14:19:25 by minkim3          ###   ########.fr       */
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
	ft_printf("ok\n");
	if (is_stack_sorted(stack_a))
		destroy_stacks_and_exit(stack_a, stack_b, 0);
	ft_printf("ok\n");
	// push_swap(stack_a, stack_b);
	display_stack(stack_a);
	destroy_stacks_and_exit(stack_a, stack_b, 0);
	return (0);
}
