# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:03:26 by yzaoui            #+#    #+#              #
#    Updated: 2023/03/30 14:39:53 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC =		./srcs/
SRC_FILES =		main.c		\
				parsing.c

DIR_UTILS =		./utils/
UTILS_FILES =	affichage.c \
				error.c

SRC =	${addprefix ${DIR_SRC}, ${SRC_FILES}} \
		${addprefix ${DIR_UTILS}, ${UTILS_FILES}}

OBJ = ${SRC:.c=.o}
NAME = push_swap
CC = cc
RM = rm -rf
FLAGS = -Wall -Werror -Wextra

MAKE_LIBFT = make -C ./libft
LIBFT_A = ./libft/libft.a

${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}

all : ${NAME}

clean :
	${MAKE_LIBFT} clean
	${RM} ${OBJ}
	
fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
