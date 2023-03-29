# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:03:26 by yzaoui            #+#    #+#              #
#    Updated: 2023/03/29 18:36:24 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC =		./srcs/
SRC_FILES =		main.c		\
				parsing.c

DIR_UTILS =		./utils/
UTILS_FILES =	affichage.c \
				error.c
				
# DIR_SRC_BONUS =		./source/checker/
# SRC_FILES_BONUS =	checker.c\
# 					c_initialisation.c\
# 					c_push.c\
# 					c_rotate.c\
# 					c_reverse_rotate.c\
# 					c_swap.c\


SRC =	${addprefix ${DIR_SRC}, ${SRC_FILES}} \
		${addprefix ${DIR_UTILS}, ${UTILS_FILES}}

OBJ = ${SRC:.c=.o}
# SRC_BONUS = ${addprefix ${DIR_SRC_BONUS}, ${SRC_FILES_BONUS}}
# OBJ_BONUS = ${SRC_BONUS:.c=.o}
NAME = push_swap
NAME_BONUS = checker
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
#	${RM} ${OBJ} ${OBJ_BONUS} quand je ferais le bonus
	
fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}
#	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

# bonus : ${NAME} ${OBJ_BONUS}
# 	${CC} ${FLAGS} ${OBJ_BONUS} ${LIBFT_A} -o ${NAME_BONUS}

.PHONY : all clean fclean re
