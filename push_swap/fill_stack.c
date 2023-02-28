/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:43:17 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 15:00:58 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(int data, int *array, int sign)
{
	if (array[data * sign] != 0)
	{
		ft_printf("duplicate error\n");
		return (-1);
	}
	array[data * sign] = sign;
	return (0);
}

static int	is_number(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	is_int(long long data)
{
	if (data > INT_MAX || data < INT_MIN)
		return (-1);
	return (0);
}

static int	valid_args(char *av, t_stack *stack_a)
{
	long long	data;
	int			sign;
	static int	array[INT_MAX] = {0};

	sign = 1;
	if (av != NULL)
	{
		if (is_number(av) == -1)
			return (-1);
		data = ft_atoi_extension(av);
		if (is_int(data) == -1)
			return (-1);
		if (data < 0)
			sign = -1;
		if (check_duplicate(data, array, sign) == -1)
			return (-1);
		push(stack_a, (int)data);
	}
	return (0);
}

int	fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (valid_args(argv[i], stack_a) == -1)
		{
			ft_putendl_fd("Error", 2);
			destroy_stack(&stack_a);
			return (-1);
		}
		i++;
	}
	return (0);
}
