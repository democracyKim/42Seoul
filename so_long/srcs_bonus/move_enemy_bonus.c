/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/20 14:07:02 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	find_enemy(t_game *map_info, int start_x, \
	int start_y, int enemy_position[2])
{
	int	y;
	int	x;

	y = start_y;
	x = start_x;
	while (y < map_info->height)
	{
		if (y != start_y)
			x = 0;
		while (x < map_info->width)
		{
			if (map_info->map[y][x] == 'M')
			{
				enemy_position[0] = y;
				enemy_position[1] = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static int	is_valid_move(t_game *map_info, int new_x, int new_y)
{
	char	new_location;

	new_location = map_info->map[new_y][new_x];
	if (new_location == '1' || new_location == 'M' || \
		new_location == 'E' || new_location == 'C')
		return (0);
	if (new_location == 'P')
	{
		print_messages("bye bye dino...\n");
		finish_game(map_info);
	}
	return (1);
}

static int	get_random_direction(void)
{
	return (rand() % 4);
}

static int	move_enemy_in_direction(t_game *map_info, \
	int direction, int enemy_position[2])
{
	int	new_x;
	int	new_y;

	new_x = enemy_position[1];
	new_y = enemy_position[0];
	if (direction == 0)
		new_y--;
	else if (direction == 1)
		new_x++;
	else if (direction == 2)
		new_y++;
	else
		new_x--;
	if (!is_valid_move(map_info, new_x, new_y))
		return (0);
	map_info->map[new_y][new_x] = 'M';
	map_info->map[enemy_position[0]][enemy_position[1]] = '0';
	enemy_position[1] = new_x;
	enemy_position[0] = new_y;
	usleep(500000);
	return (1);
}

void	move_enemy(t_game *map_info)
{
	static int	enemy_move_counter;
	int			enemy_position[2];
	int			direction;

	ft_memset(enemy_position, 0, sizeof(enemy_position));
	if (find_enemy(map_info, enemy_position[1], \
		enemy_position[0], enemy_position) == 1)
	{
		enemy_move_counter++;
		if (enemy_move_counter < MOVE_THRESHOLD)
			return ;
		enemy_move_counter = 0;
		direction = get_random_direction();
		if (!move_enemy_in_direction(map_info, direction, enemy_position))
			return ;
		move_enemy(map_info);
	}
	return ;
}
