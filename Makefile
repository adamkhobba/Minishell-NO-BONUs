# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 19:33:36 by akhobba           #+#    #+#              #
#    Updated: 2024/05/18 08:25:50 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CFLAGS =  -Wall -Wextra -Werror

SRC = main.c 

OBJ = ${SRC.c:.o}

NAME = minishell 

all : libft ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -Llibft

libft :
	make -C libft

clean :
	rm -rf ${OBJ}
	rm -rf ${NAME}
	
fclean : clean

re : fclean all