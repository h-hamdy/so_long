/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:26:41 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/25 13:27:47 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

/****************PLAYER******************/
# define RIGHT 	"pic_xpm/right.xpm"
# define UP		"pic_xpm/up.xpm"
# define DOWN	"pic_xpm/down.xpm"
# define LEFT	"pic_xpm/left.xpm"

/****************COINS********************/
# define COIN1	"pic_xpm/coin1.xpm"
# define COIN2	"pic_xpm/coin2.xpm"
# define COIN3	"pic_xpm/coin3.xpm"
# define COIN4	"pic_xpm/coin4.xpm"
# define COIN5	"pic_xpm/coin5.xpm"
# define COIN6	"pic_xpm/coin6.xpm"

/****************OTHER*********************/
# define BOX 	"pic_xpm/box.xpm"
# define DOOR 	"pic_xpm/close_door.xpm"
# define BOMB 	"pic_xpm/bomb.xpm"
# define GROUND	"pic_xpm/ground.xpm"

typedef struct s_game
{
	int		width;
	int		height;
	void	*mlx;
	void	*img;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		money;
	int		count;

}			t_game;

char	*get_next_line(int fd);
char	**check_map(char *av);
char	*read_file(int fd);
void	raise_error(char c);
void	display_window(t_game game);
int		calcul_len(char **lines, char c);
int		launch_game(int key, t_game *game);
int		find_player(t_game *game, char c);
void	display_box(t_game *game);
void	calcul_money(t_game *game);
int		animation(t_game *game);
void	display_count(t_game *game, int key);
int		ft_check(t_game *game, int x, int y);

#endif