# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 15:25:57 by matoledo          #+#    #+#              #
#    Updated: 2026/04/21 21:52:39 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc

# -O0 -fno-omit-frame-pointer
CFLAGS = -g -Wall -Werror -Wextra

LFLAG =  -L include/libft -lft -L include/mlx -lmlx -lXext -lX11 -lm

IFLAGS = -I include -Imlx -Ilibft

NAME = cub3D

SRC = src/main.c src/parse/store_map.c src/parse/parse_free.c src/parse/parse_init.c \
src/parse/parse_utils.c src/parse/check_textures.c src/parse/check_map.c src/parse/map_utils.c \
src/ray_cast/free.c src/ray_cast/screen.c src/ray_cast/player.c src/ray_cast/render.c src/ray_cast/world_info.c src/ray_cast/ray_cast.c src/ray_cast/textures.c\
src/ray_cast/loop/key_events.c src/ray_cast/loop/mouse_events.c src/ray_cast/loop/game_loop.c src/ray_cast/loop/movement.c src/ray_cast/loop/rotation.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C include/mlx all
	@$(MAKE) -C include/libft all
	@$(CC) -o $(NAME) $(OBJ) $(LFLAG)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"

clean:
	@$(MAKE) -C include/libft clean
	@$(MAKE) -C include/mlx clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	
fclean: clean
	@$(MAKE) -C include/libft fclean
	@$(MAKE) -C include/mlx clean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
