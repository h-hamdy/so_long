/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:46:58 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/24 00:02:34 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This function read from the file -> EOF
char	*read_file(int fd)
{
	char	*line;
	char	*str;
	char	*tmp;

	line = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		tmp = line;
		line = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		str = get_next_line(fd);
	}
	return (line);
}

// Error handling comments
void	raise_error(char c)
{
	if (c == 'a')
		ft_printf("Invalid argumet.\n");
	else if (c == 'M')
		ft_printf("No coins to eat\n");
	else if (c == 'm')
		ft_printf("Invalid map.\n");
	else if (c == 'E')
		ft_printf("No exit\n");
	else if (c == 'p')
		ft_printf("More than 1 player or player does not exist.\n");
	else if (c == 'f')
		ft_printf("The file most end with .ber.\n");
	else if (c == 'F')
		ft_printf("File not found\n");
	else if (c == 'w')
		ft_printf("Walls error.\n");
	else if (c == 'c')
		ft_printf("Invalide components.\n");
	else if (c == 'l')
		ft_printf("Map length error.\n");
	exit(1);
}

// find 'P' character in a double pointer
int	find_player(t_game *game, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				if (c == 'r')
					return (i);
				else if (c == 'c')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (game->money);
}

void	make_box(t_game *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, BOX, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		x * 32, (y - 1) * 32);
	mlx_destroy_image(game->mlx, game->img);
}

// this function display box
void	display_box(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (x < 2 && (y == 1 || y == 0))
			{
				x++;
				continue ;
			}
			if (game->map[y][x] == '1')
				make_box(game, x, y);
			x++;
		}
		y++;
	}
}
