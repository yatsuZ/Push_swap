# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:03:26 by yzaoui            #+#    #+#              #
#    Updated: 2023/05/29 19:18:26 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = ./srcs/main.c

DIR_SRC =		./srcs/
SRC_FILES =		parsing.c

DIR_TRIE =		./srcs/trie/
TRIE_FILES =	optimisation_trie.c	\
				trie_5_ou_moin.c	\
				trie_de_3.c			\
				trie_general.c		\
				verif_trie.c

DIR_UTILS =		./utils/
UTILS_FILES =	affichage.c		\
				convertisseur.c	\
				struct_free.c	\
				struct.c		\
				utile.c

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

SRC_WITHOUT_MAIN =	${addprefix ${DIR_SRC}, ${SRC_FILES}}		\
					${addprefix ${DIR_UTILS}, ${UTILS_FILES}}	\
					${addprefix ${DIR_TRIE}, ${TRIE_FILES}}		\
					${addprefix ${DIR_INSTRUCTION}, ${INSTRUCTION_FILES}}

SRC =	${SRC_MAIN} \
		${SRC_WITHOUT_MAIN}

DIR_BONUS =		./bonus/
BONUS_FILES =	main.c								\
				parsing_param.c						\
				struct_bonus.c

SRC_BONUS =	${addprefix ${DIR_BONUS}, ${BONUS_FILES}}	\
			${SRC_WITHOUT_MAIN}

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
NAME = push_swap
NAME_BONUS = checker
CC = cc
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -g3

MAKE_LIBFT = make -s -C ./libft
LIBFT_A = ./libft/libft.a

${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}

all : ${NAME}

bonus: ${OBJ_BONUS}
	${MAKE_LIBFT}
	${CC} ${FLAGS} ${OBJ_BONUS} ${LIBFT_A} -o ${NAME_BONUS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re : fclean all

################# Commande perso

# Verifie la norminette
norme:
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
