# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 19:33:36 by akhobba           #+#    #+#              #
#    Updated: 2024/05/18 08:44:30 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = ${SRC:.c=.o}
NAME = minishell

.PHONY: all libft clean fclean re

all: ${NAME}

${NAME}: ${OBJ} libft/libft.a
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -lreadline libft/libft.a

libft/libft.a:
	make -C libft

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all
