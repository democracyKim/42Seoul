/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:16:53 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/21 15:41:17 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/so_long.h"
// #include "./srcs_bonus/so_long_bonus.h"

static int	validate_arg(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", \
		ft_strlen(ft_strrchr(av[1], '.'))) != 0)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	return (1);
}
void check_leaks() { system("leaks so_long.out"); } 

int	main(int ac, char **av)
{
	atexit(check_leaks);
	if (validate_arg(ac, av) == ERROR)
		return (0);
	so_long(av[1]);
	return (0);
}
