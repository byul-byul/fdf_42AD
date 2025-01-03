# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 12:12:00 by bhajili           #+#    #+#              #
#    Updated: 2024/12/27 13:02:24 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   minitalk

D_HDR   =   ./
D_SRC   =   ./

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   $(D_SRC)server.c \
            $(D_SRC)client.c \
			$(D_SRC)utils.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

$(NAME): server client

bonus: server client

# Server and client linking with dependencies on object files
server: server.o utils.o libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft

client: client.o utils.o libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft

# Library rule to build libft if needed
libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re bonus