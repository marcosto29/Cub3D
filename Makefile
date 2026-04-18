# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 13:17:46 by matoledo          #+#    #+#              #
#    Updated: 2026/04/06 12:36:06 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LFLAGS =   -L./include/mlx -lmlx -lXext -lX11 -lm

IFLAGS = -Iinclude/mlx

SRCS = main.c free.c screen.c player.c render.c world_info.c\
		loop/key_events.c loop/mouse_events.c loop/game_loop.c loop/movement.c loop/visual.c

OBJS = $(SRCS:.c=.o)

NAME = main

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./include/mlx all
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	@$(CC) -c $(IFLAGS) $(CFLAGS) $< -o $@

clean:
	@$(MAKE) -C ./include/mlx clean
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C ./include/mlx clean
	@rm -rf $(NAME)

re: fclean all
	@$(MAKE) -C ./include/mlx re