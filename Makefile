# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 15:25:57 by matoledo          #+#    #+#              #
#    Updated: 2026/04/20 19:51:00 by aosset-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g -O0 -fno-omit-frame-pointer

LIBFT_PATH = include/libft


LIBFT = $(LIBFT_PATH)/libft.a


NAME = cub3D
SRC = src/main.c src/parse/store_map.c src/parse/parse_free.c src/parse/parse_init.c \
src/parse/parse_utils.c src/parse/check_textures.c src/parse/check_map.c src/parse/map_utils.c

OBJ = $(SRC:.c=.o)

HEADER = include/cub3d.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
%.o: %.c
	@$(CC) $(CFLAGS) -I include -I$(LIBFT_PATH)  -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
re: fclean all

.PHONY: all clean fclean re