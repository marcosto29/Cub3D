# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 16:12:21 by aosset-o          #+#    #+#              #
#    Updated: 2026/04/20 10:30:13 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -fPIE

NAME = libft.a
SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c get_next_line.c get_next_line_buffer.c \
		ft_free_double.c ft_size.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h
RM = rm -f

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	
clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all