/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:27:01 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/25 13:31:32 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_game *game)
{
	if (ft_check(game, game->player_y - 1, game->player_x) == 0)
		return ;
	game->img = mlx_xpm_file_to_image(game->mlx, UP, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player_x * 32, (game->player_y - 1) * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, GROUND, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player_x * 32, game->player_y * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->player_y--;
}

void	key_d(t_game *game)
{
	if (ft_check(game, game->player_y, game->player_x + 1) == 0)
		return ;
	game->img = mlx_xpm_file_to_image(game->mlx, RIGHT, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(game->player_x + 1) * 32, (game->player_y) * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, GROUND, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player_x * 32, game->player_y * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->player_x++;
}

void	key_s(t_game *game)
{
	if (ft_check(game, game->player_y + 1, game->player_x) == 0)
		return ;
	game->img = mlx_xpm_file_to_image(game->mlx, DOWN, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(game->player_x) * 32, (game->player_y + 1) * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, GROUND, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player_x * 32, game->player_y * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->player_y++;
}

void	key_a(t_game *game)
{
	if (ft_check(game, game->player_y, game->player_x - 1) == 0)
		return ;
	game->img = mlx_xpm_file_to_image(game->mlx, LEFT, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(game->player_x - 1) * 32, (game->player_y) * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, GROUND,
			&game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player_x * 32, game->player_y * 32);
	mlx_destroy_image(game->mlx, game->img);
	game->player_x--;
}

int	launch_game(int key, t_game *game)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		key_w(game);
	else if (key == 2)
		key_d(game);
	else if (key == 1)
		key_s(game);
	else if (key == 0)
		key_a(game);
	display_box(game);
	display_count(game, key);
	return (0);
}
