/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:39 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 10:16:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded_by_wall(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width -1] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

static int	count_component(char component, t_game *map_info)
{
	if (component == 'C')
		map_info->num_cepm[0]++;
	else if (component == 'E')
		map_info->num_cepm[1]++;
	else if (component == 'P')
		map_info->num_cepm[2]++;
	else if (component == 'M')
		map_info->num_cepm[3]++;
	else if (component == '0' || component == '1')
		return (1);
	else
		return (ERROR);
	return (1);
}

static int	check_component(t_game *map_info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map_info->height)
	{
		x = -1;
		while (++x < map_info->width)
		{
			if (count_component(map_info->map[y][x], map_info) == ERROR)
				return (ERROR);
			if (map_info->map[y][x] == 'P')
			{
				map_info->player_position[0] = y;
				map_info->player_position[1] = x;
			}
		}
	}
	if (map_info->num_cepm[0] < 1 || \
		map_info->num_cepm[1] != 1 || \
		map_info->num_cepm[2] != 1)
		return (ERROR);
	return (0);
}

int	check_map(t_game *map_info)
{
	if (check_component(map_info) == ERROR)
	{
		print_error("map error\n");
		return (ERROR);
	}
	if (is_surrounded_by_wall(map_info->map, map_info->height, \
			map_info->width) == ERROR)
	{
		print_error("map error\n");
		return (ERROR);
	}
	if (check_route(map_info, map_info->player_position) == ERROR)
	{
		print_error("map error\n");
		return (ERROR);
	}
	return (0);
}
