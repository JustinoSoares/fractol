# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoares <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 16:40:03 by jsoares           #+#    #+#              #
#    Updated: 2024/07/30 16:40:04 by jsoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
NAME = fractol
PROG =  fractol.c ft_init.c \
	math_utils.c render.c \
        string_utilits.c \
        events.c
OBJ_PROG = $(PROG: .c=.o)
OBJS = fractol.o ft_init.o \
       math_utils.o render.o \
       string_utilits.o \
       events.o
#INCLUDE = -I./

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(PROG) $(CFLAGS) -o $(NAME)
clean:
	@rm -r $(OBJS)
fclean:
	@rm -r $(NAME)
	@rm -r $(OBJS)
re: fclean all
.PHONY: all clean fclean re
