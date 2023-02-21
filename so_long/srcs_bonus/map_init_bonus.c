/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:12:59 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/20 14:06:53 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_rectangular(char (*tmp)[1000], t_game *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (tmp[i][j])
			j++;
		if (i != map_info->height - 1)
			j--;
		if (map_info->width != j)
			return (ERROR);
		i++;
	}
	return (1);
}

static void	copy_map(char (*tmp)[1000], t_game *map_info)
{
	int	i;

	map_info->map = malloc(sizeof(char *) * map_info->height);
	i = 0;
	while (i < map_info->height)
	{
		map_info->map[i] = malloc(sizeof(char) * map_info->width);
		ft_memcpy(map_info->map[i], tmp[i], map_info->width);
		i++;
	}
}

static int	open_map(char (*tmp)[1000], t_game *map_info, char *map_file)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = -1;
		while (line[++j])
			tmp[i][j] = line[j];
		i++;
		free(line);
	}
	map_info->width = j;
	map_info->height = i;
	return (0);
}

int	map_init(t_game *map_info, char *map_file)
{
	char	tmp[1000][1000];

	if (open_map(tmp, map_info, map_file) == ERROR)
	{
		print_error("open error\n");
		return (ERROR);
	}
	if (check_rectangular(tmp, map_info) == ERROR)
	{
		print_error("map_init_error\n");
		return (ERROR);
	}
	copy_map(tmp, map_info);
	return (1);
}
