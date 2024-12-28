# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 12:10:48 by bhajili           #+#    #+#              #
#    Updated: 2024/12/28 14:13:01 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf

D_HDR   =   ./incl/
D_SRC   =   ./srcs/

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   $(D_SRC)main.c \
            $(D_SRC)fdf.c \
			$(D_SRC)validator.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

# linking with dependencies on object files
$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	$(CC) -o $@ $^ -Llibft -lft  -Lminilibx -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit

# Library rule to build libft if needed
minilibx/libmlx.a:
	make -C minilibx

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C minilibx clean

fclean: clean
	rm -f libft/libft.a minilibx/libmlx.a $(NAME)

re: fclean all

.PHONY: all libft clean fclean re bonus