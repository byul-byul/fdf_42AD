# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 18:01:15 by bhajili           #+#    #+#              #
#    Updated: 2024/12/29 12:18:46 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

D_HDR	=	./
D_SRC	=	./

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(D_SRC)ft_printf.c \
			$(D_SRC)arg_handler.c \
			$(D_SRC)arg_printer.c \
			$(D_SRC)num_printer.c \
			$(D_SRC)get_num_type.c \
			$(D_SRC)utils.c

OBJS	=	${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	-I $(D_HDR)

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: ${NAME}

.PHONY:	all clean fclean re bonus