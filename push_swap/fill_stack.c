/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:43:17 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/08 18:26:27 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(t_stack *stack, int data)
{
	t_stack_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == data)
			return (ERROR);
		tmp = tmp->next;
	}
	return (0);
}

static int	is_number(char *string)
{
	int			i;

	i = 0;
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (ERROR);
		i++;
	}
	return (0);
}

static int	is_int(long long data)
{
	if (data > INT_MAX || data < INT_MIN)
		return (ERROR);
	return (0);
}

int	valid_args(char *av, t_stack *stack_a)
{
	long long	data;
	char		**numbers;
	int			i;

	if (av == NULL)
		return (error_return("Error\n", ERROR));
	i = 0;
	numbers = ft_split(av, ' ');
	if (!numbers)
		error_exit(stack_a, NULL);
	while (numbers[i])
	{
		if (is_number(numbers[i]) == ERROR)
			error_exit(stack_a, NULL);
		data = ft_atoi_extension(numbers[i]);
		if (is_int(data) == ERROR)
			error_exit(stack_a, NULL);
		if (check_duplicate(stack_a, (int)data) == ERROR)
			error_exit(stack_a, NULL);
		push(stack_a, (int)data);
		i++;
	}
	free_two_dementional_array(numbers);
	return (0);
}

int	fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (valid_args(argv[i], stack_a) == ERROR)
		{
			destroy_stack(&stack_a);
			return (ERROR);
		}
		i++;
	}
	return (0);
}
