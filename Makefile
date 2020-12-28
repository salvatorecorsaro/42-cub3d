# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 12:44:48 by scorsaro          #+#    #+#              #
#    Updated: 2020/12/28 12:44:53 by scorsaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang

CFLAGS = -O3 -Wall -Wextra -Werror

MLX = mlx/apple

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h macros.h structs.h functions.h



SRC = checkers.c \
			closing.c \
			color_parsing.c \
			config_parsing.c \
			cub3d.c \
			gnl.c \
			input.c \
			libft.c \
			libft_2.c \
			libft_3.c \
			map_parsing.c \
			map_parsing_2.c \
			movement.c \
			raycasting.c \
			raycasting_2.c \
			save_screenshot.c \
			sprites.c \
			structs_initializer.c \
			textures_processing.c \



OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re test sqr bmp err inv norm bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ) $(B_OBJ)
	rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	./$(NAME) map.cub

hole: re
	./$(NAME) map_hole.cub

save: re
	./$(NAME) map.cub --save

err: re
	./$(NAME) none

inv: re
	./$(NAME) map_invalid.cub

norm:
	norminette $(SRC) $(HEADER)

bonus: re
	./$(NAME) map.cub