/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:39 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 09:58:33 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_player_position(t_game *map_info, int *player_position)
{
	char	**map;
	int		y;
	int		x;

	map = map_info->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player_position[0] = y;
				player_position[1] = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}

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

static int	check_forbidden_component(char component)
{
	if (component == 'P' || component == 'C' || \
		component == 'E' || component == 'M' || \
		component == '0' || component == '1')
		return (1);
	return (ERROR);
}

static int	check_component(t_game *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (check_forbidden_component(map_info->map[i][j]) == ERROR)
				return (ERROR);
			if (map_info->map[i][j] == 'C')
				map_info->collect_exit_player[0]++;
			else if (map_info->map[i][j] == 'E')
				map_info->collect_exit_player[1]++;
			else if (map_info->map[i][j] == 'P')
				map_info->collect_exit_player[2]++;
		}
	}
	if (map_info->collect_exit_player[0] < 1 || \
		map_info->collect_exit_player[1] != 1 || \
		map_info->collect_exit_player[2] != 1)
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
	if (get_player_position(map_info, map_info->player_position) == ERROR)
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
