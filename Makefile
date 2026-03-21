# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 13:17:46 by matoledo          #+#    #+#              #
#    Updated: 2026/03/21 17:26:55 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LFLAGS =   -L./include/mlx -lmlx -lXext -lX11 -lm

IFLAGS = -Iinclude/mlx

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

NAME = main

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./include/mlx all
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	@$(CC) -c $(IFLAGS) $(CFLAGS) $< 

clean:
	@$(MAKE) -C ./include/mlx clean
	@rm -rf *.o

fclean: clean
	@$(MAKE) -C ./include/mlx clean
	@rm -rf $(NAME)

re: fclean all
	@$(MAKE) -C ./include/mlx re