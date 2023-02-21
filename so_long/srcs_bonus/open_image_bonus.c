/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/20 15:41:06 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*xpm_to_image(t_game *image, char *address)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(image->mlx, address, &width, &height));
}

static void	open_dino(t_game *image)
{
	int		i;
	char	*right_path;
	char	*left_path;

	i = 0;
	while (i < 15)
	{
		right_path = ft_strjoin("./images/dino/right/", ft_itoa(i + 1));
		left_path = ft_strjoin("./images/dino/left/", ft_itoa(i + 1));
		image->dino_right[i] = xpm_to_image(image, right_path);
		image->dino_left[i] = xpm_to_image(image, left_path);
		free(right_path);
		free(left_path);
		i++;
	}
}

static void	open_components(t_game *image)
{
	image->enemy[0] = xpm_to_image(image, "./images/enemy/1.xpm");
	image->enemy[1] = xpm_to_image(image, "./images/enemy/2.xpm");
	image->item = xpm_to_image(image, "./images/item.xpm");
	image->road = xpm_to_image(image, "./images/road.xpm");
	image->spellbook = xpm_to_image(image, "./images/spellbook.xpm");
	image->wall = xpm_to_image(image, "./images/wall.xpm");
}

void	open_image(t_game *image)
{
	image->mlx = mlx_init();
	image->dino_advanture = mlx_new_window(image->mlx, \
		image->width * 64, image->height * 64, "dino_advanture");
	open_dino(image);
	open_components(image);
}
