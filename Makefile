# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 07:29:42 by hhamdy            #+#    #+#              #
#    Updated: 2022/03/27 17:13:49 by hhamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror #-fsanitize=address -g

NAME 	= 	so_long

LIBFT	=	libft/libft.a

PRINTF  =  printf/libftprintf.a

SRC		=   so_long.c \
			check_map.c \
			utils.c \
			utils2.c \
			display_window.c \
			launch_game.c \
			animation.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

OBJS 	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

clean:
	make clean -C libft
	make clean -C printf
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf printf/libftprintf.a
	rm -rf $(NAME)

re: fclean all
