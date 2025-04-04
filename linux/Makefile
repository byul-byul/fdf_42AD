# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 12:10:48 by bhajili           #+#    #+#              #
#    Updated: 2025/04/04 23:29:48 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf

D_HDR   =   ./incl/
D_SRC   =   ./srcs/

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror -g

SRCS    =   $(D_SRC)main.c \
			$(D_SRC)fdf.c \
            $(D_SRC)validator.c \
			$(D_SRC)initializator_00.c \
			$(D_SRC)initializator_01.c \
			$(D_SRC)parser.c \
			$(D_SRC)projection.c \
			$(D_SRC)colorant.c \
			$(D_SRC)event_handler_00.c \
			$(D_SRC)event_handler_01.c \
			$(D_SRC)event_handler_02.c \
			$(D_SRC)transformer_00.c \
			$(D_SRC)transformer_01.c \
			$(D_SRC)rotation.c \
			$(D_SRC)cleaner.c \
			$(D_SRC)render.c \
			$(D_SRC)utils_00.c \
			$(D_SRC)utils_01.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

# linking with dependencies on object files
$(NAME): $(OBJS) libft/libft.a minilibx-linux/libmlx.a
	$(CC) -o $@ $^ -Llibft -lft -Lminilibx-linux -lmlx -lX11 -lXext -lm

# Library rule to build minilibx if needed
minilibx-linux/libmlx.a:
	make -C minilibx-linux

# Library rule to build libft if needed
libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f libft/libft.a minilibx-linux/libmlx.a $(NAME)

re: fclean all

.PHONY: all libft clean fclean re