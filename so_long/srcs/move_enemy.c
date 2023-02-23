/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 09:25:03 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_enemy(t_game *game, int start_x, \
	int start_y, int enemy_position[2])
{
	int	y;
	int	x;

	y = start_y;
	x = start_x;
	while (y < game->height)
	{
		if (y != start_y)
			x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'M')
			{
				enemy_position[0] = y;
				enemy_position[1] = x;
				return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	char	new_location;

	new_location = game->map[new_y][new_x];
	if (new_location == '1' || new_location == 'M' || \
		new_location == 'E' || new_location == 'C')
		return (0);
	if (new_location == 'P')
	{
		print_messages("bye bye dino...\n");
		finish_game(game);
	}
	return (1);
}

static int	get_random_direction(void)
{
	return (rand() % 4);
}

static int	move_enemy_in_direction(t_game *game, \
	int direction, int *enemy_position)
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
	else if (direction == 3)
		new_x--;
	else
		return (0);
	if (!is_valid_move(game, new_x, new_y))
		return (0);
	game->map[new_y][new_x] = 'M';
	game->map[enemy_position[0]][enemy_position[1]] = '0';
	put_image(game, enemy_position[1], enemy_position[0], game->road);
	put_image(game, new_x, new_y, game->enemy[(new_x + new_y) % 2]);
	enemy_position[1] = new_x;
	enemy_position[0] = new_y;
	return (1);
}

void	move_enemy(t_game *game)
{
	static int	enemy_move_counter;
	int			enemy_position[2];
	int			direction;
	int			num_enemy;

	num_enemy = game->num_cepm[3];
	ft_memset(enemy_position, 0, sizeof(enemy_position));
	enemy_move_counter++;
	if (enemy_move_counter < MOVE_THRESHOLD)
		return ;
	enemy_move_counter = 0;
	while (num_enemy)
	{
		if (find_enemy(game, enemy_position[1], \
			enemy_position[0], enemy_position) == -1)
			return ;
		direction = get_random_direction();
		if (!move_enemy_in_direction(game, direction, &enemy_position[0]))
			continue ;
		num_enemy--;
		enemy_position[1]++;
	}
	return ;
}
