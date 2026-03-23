# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 15:36:39 by aosset-o          #+#    #+#              #
#    Updated: 2026/03/23 17:10:14 by aosset-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g -O0 -fno-omit-frame-pointer

LIBFT_PATH = include/libft
MLX_PATH = include/mlx

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

NAME = cub3D
SRC = src/main.c src/parse/store_map.c src/parse/parse_free.c src/parse/parse_init.c \
src/parse/parse_utils.c src/parse/check_textures.c src/parse/check_map.c src/parse/map_utils.c

OBJ = $(SRC:.c=.o)

HEADER = include/cub3d.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm 
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
%.o: %.c
	@$(CC) $(CFLAGS) -I include -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"
$(MLX):
	@$(MAKE) -C $(MLX_PATH)
	@echo "$(NAME): $(GREEN)$(MLX) was created$(RESET)"
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@$(MAKE) -C $(MLX_PATH) clean
	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
re: fclean all

.PHONY: all clean fclean re