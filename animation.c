/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:55:44 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/13 18:47:15 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_ground(t_game *game, int i, int j)
{
	game->img = mlx_xpm_file_to_image(game->mlx, GROUND, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img, j * 32, i * 32);
	mlx_destroy_image(game->mlx, game->img);
}

void	make_anim(t_game *game, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				put_ground(game, i, j);
				game->img = mlx_xpm_file_to_image(game->mlx, path,
						&game->x, &game->y);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					j * 32, i * 32);
				mlx_destroy_image(game->mlx, game->img);
			}
			j++;
		}
		i++;
	}
	display_box(game);
}

void	animation_utils(int *img_c)
{
	if (*img_c == 0 || *img_c == 1 || *img_c == 2 || *img_c == 3 || *img_c == 4)
		*img_c = *img_c + 1;
	else if (*img_c == 5)
		*img_c = 0;
}

int	animation(t_game *game)
{
	static int	nors;
	static int	img_c;

	if (nors > 1000)
	{
		if (img_c == 0)
			make_anim(game, COIN1);
		else if (img_c == 1)
			make_anim(game, COIN2);
		else if (img_c == 2)
			make_anim(game, COIN3);
		else if (img_c == 3)
			make_anim(game, COIN4);
		else if (img_c == 4)
			make_anim(game, COIN5);
		else if (img_c == 5)
			make_anim(game, COIN6);
		animation_utils(&img_c);
		nors = 0;
	}
	else
		nors++;
	return (0);
}
