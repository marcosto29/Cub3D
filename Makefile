# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 15:25:57 by matoledo          #+#    #+#              #
#    Updated: 2026/04/18 15:42:02 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc

# -O0 -fno-omit-frame-pointer
CFLAGS = -g -Wall -Werror -Wextra

MLXFLAG =   -L./include/mlx -lmlx -lXext -lX11 -lm

IFLAGS = -Iinclude/mlx -Iinclude/libft

NAME = cub3D

HEADER = include/cub3d.h

SRC = src/main.c src/parse/store_map.c src/parse/parse_free.c src/parse/parse_init.c \
src/parse/parse_utils.c src/parse/check_textures.c src/parse/check_map.c src/parse/map_utils.c \
src/ray_cast/free.c src/ray_cast/screen.c src/ray_cast/player.c src/ray_cast/render.c src/ray_cast/world_info.c\
src/ray_cast/loop/key_events.c src/ray_cast/loop/mouse_events.c src/ray_cast/loop/game_loop.c src/ray_cast/loop/movement.c src/ray_cast/loop/visual.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm 
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./include/libft all
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"
$(MLX):
	@$(MAKE) -C ./include/mlx all
	@echo "$(NAME): $(GREEN)$(MLX) was created$(RESET)"


clean:
	@$(MAKE) -C ./include/libft clean
	@$(MAKE) -C ./include/mlx clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	
fclean: clean
	@$(MAKE) -C ./include/libft fclean
	@$(MAKE) -C ./include/mlx fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@$(MAKE) -C $(MLX_PATH) clean
	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
