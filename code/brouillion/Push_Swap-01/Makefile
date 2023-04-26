# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:03:26 by yzaoui            #+#    #+#              #
#    Updated: 2023/04/26 02:12:39 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC =		./srcs/
SRC_FILES =		main.c			\
				parsing.c		\
				trie_de_3.c		\
				trie_general.c

DIR_UTILS =		./utils/
UTILS_FILES =	affichage.c		\
				convertisseur.c	\
				error_text.c	\
				error.c			\
				struct_free.c	\
				struct.c

DIR_INSTRUCTION =	./Instruction/
INSTRUCTION_FILES = instructions.c					\
					push_a.c						\
					push_b.c						\
					reverse_rotate_a.c				\
					reverse_rotate_b.c				\
					reverse_rotate_reverse_rotate.c	\
					rotate_a.c						\
					rotate_b.c						\
					rotate_rotate.c					\
					swap_a.c						\
					swap_b.c						\
					swap_swap.c


SRC =	${addprefix ${DIR_SRC}, ${SRC_FILES}}		\
		${addprefix ${DIR_UTILS}, ${UTILS_FILES}}	\
		${addprefix ${DIR_INSTRUCTION}, ${INSTRUCTION_FILES}}	\

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
	@ clear
	@ if ! norminette | grep "Error"; then echo "\033[32mOK!\033[0m"; fi

propre:
	@ make all -s
	@ make clean -s

test:
	@ clear
	@ make propre -s
	@ echo "Resultat du programme ./push_swap : "
	@ echo
	@ ./push_swap

val:
	@ clear
	@ make propre -s
	@ echo "Resultat du programme ./push_swap : "
	@ echo
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap

#################

.PHONY : all clean fclean re
