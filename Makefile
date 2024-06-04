# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 19:33:36 by akhobba           #+#    #+#              #
#    Updated: 2024/06/04 10:54:06 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c  parsing/lexer.c parsing/def_type.c parsing/parser.c\
		parsing/check_command.c parsing/check_redirections.c\
		utils/ft_split.c utils/small_ft.c utils/ft_lstadd_front_bonus.c utils/error.c\
		utils/ft_atoi.c utils/ft_strcmp.c utils/ft_lstadd_back_bonus.c\
		utils/ft_lstnew_bonus.c utils/ft_lstdelone_bonus.c utils/ft_lstlast_bonus.c\
		utils/ft_lstsize_bonus.c utils/ft_strdup.c utils/ft_free.c utils/ft_strlen.c\
		utils/ft_lstclear_bonus.c utils/ft_putstr.c utils/ft_strchr.c utils/command.c\
		utils/ft_lst_redi.c
OBJ = ${SRC:.c=.o}

NAME = minishell

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -lreadline 

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all