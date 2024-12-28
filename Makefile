# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 12:10:48 by bhajili           #+#    #+#              #
#    Updated: 2024/12/28 13:21:21 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf

D_HDR   =   ./
D_SRC   =   ./srcs

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   $(D_SRC)main.c \
            $(D_SRC)fdf.c \
			$(D_SRC)validator.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

# linking with dependencies on object files
$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft

# Library rule to build libft if needed
libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f libft/libft.a $(NAME)

re: fclean all

.PHONY: all libft clean fclean re bonus