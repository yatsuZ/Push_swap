# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:03:26 by yzaoui            #+#    #+#              #
#    Updated: 2023/03/31 15:20:38 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC =		./srcs/
SRC_FILES =		main.c			\
				parsing.c

DIR_UTILS =		./utils/
UTILS_FILES =	affichage.c		\
				error_text.c	\
				error.c			\
				struct.c

SRC =	${addprefix ${DIR_SRC}, ${SRC_FILES}} \
		${addprefix ${DIR_UTILS}, ${UTILS_FILES}}

OBJ = ${SRC:.c=.o}
NAME = push_swap
CC = cc
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -g3

MAKE_LIBFT = make -s -C ./libft
LIBFT_A = ./libft/libft.a

${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}

all : ${NAME}

propre:
	@ make all -s
	@ make clean -s

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}

re : fclean all

################# Commande perso

# Verifie la norminette
norme :
	@ if ! norminette | grep "Error"; then echo "\033[32mOK!\033[0m"; fi

#################

.PHONY : all clean fclean re
