/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:53:04 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/14 12:22:31 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_ground(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game.width)
	{
		y = 0;
		while (y < game.height)
		{
			mlx_put_image_to_window(game.mlx, game.win,
				game.img, x * 32, y * 32);
			y++;
		}
		x++;
	}
}

// This function check the conpoment and replaset with the exact img
void	display_conpoment(t_game game, char c, int width, int height)
{
	if (c == 'P')
		game.img = mlx_xpm_file_to_image(game.mlx, RIGHT, &game.x, &game.y);
	else if (c == 'C')
		game.img = mlx_xpm_file_to_image(game.mlx, COIN1, &game.x, &game.y);
	else if (c == '1')
	{
		game.img = mlx_xpm_file_to_image(game.mlx, BOX, &game.x, &game.y);
		mlx_put_image_to_window(game.mlx, game.win, game.img,
			width * 32, height * 32 - 32);
		return ;
	}
	else if (c == 'E')
		game.img = mlx_xpm_file_to_image(game.mlx, DOOR, &game.x, &game.y);
	else if (c == 'H')
		game.img = mlx_xpm_file_to_image(game.mlx, BOMB, &game.x, &game.y);
	mlx_put_image_to_window(game.mlx, game.win, game.img,
		width * 32, height * 32);
}

// This function loop into the file
void	loop_file(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			display_conpoment(game, game.map[i][j], j, i);
			j++;
		}
		i++;
	}
}

int	exit_func(void)
{
	exit(0);
	return (0);
}

void	display_window(t_game game)
{
	game.width = calcul_len(game.map, 'w');
	game.height = calcul_len(game.map, 'h');
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32,
			"9asser maa rassek");
	game.img = mlx_xpm_file_to_image(game.mlx, GROUND, &game.x, &game.y);
	display_ground(game);
	loop_file(game);
	game.player_x = find_player(&game, 'c');
	game.player_y = find_player(&game, 'r');
	calcul_money(&game);
	mlx_hook(game.win, 2, 0, launch_game, &game);
	mlx_hook(game.win, 17, 0, exit_func, 0);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
}
