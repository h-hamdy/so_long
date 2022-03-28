/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:01:00 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/25 13:35:12 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this function calculate the amount of the money in the game
void	calcul_money(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->money++;
			if (game->map[i][j] == 'E')
				flag++;
			j++;
		}
		i++;
	}
	if (game->money == 0)
		raise_error('M');
	if (flag == 0)
		raise_error('E');
}

// this function calculate the len of a double pointer
int	calcul_len(char **lines, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == 'w')
	{
		while (lines[0][i])
			i++;
	}
	else
	{
		while (lines[i])
			i++;
	}
	return (i);
}

void	display_count(t_game *game, int key)
{
	char	*res;
	int		i;

	if (key == 13 || key == 2 || key == 1 || key == 0)
	{
		ft_printf("%d\n", ++game->count);
		res = ft_itoa(game->count);
		game->img = mlx_xpm_file_to_image(game->mlx, BOX, &game->x, &game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->img,
			1 * 32, (-1) * 32);
		i = 0;
		while (i < game->height)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img,
				0, (i - 1) * 32);
			i++;
		}
		mlx_string_put(game->mlx, game->win, 0, 0, 0xffffff,
			res);
		free(res);
	}
}

int	ft_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E' && game->money == 0)
		exit (1);
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->money--;
	}
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->money != 0)
		return (0);
	if (game->map[y][x] == 'H')
		exit(0);
	return (1);
}
