# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:02:58 by yzaoui            #+#    #+#              #
#    Updated: 2023/03/28 18:50:29 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_isalpha.c					\
		ft_isdigit.c					\
		ft_isalnum.c					\
		ft_isascii.c					\
		ft_isprint.c					\
		ft_strlen.c						\
		ft_memset.c						\
		ft_bzero.c						\
		ft_memcpy.c						\
		ft_memmove.c					\
		ft_strlcpy.c					\
		ft_strlcat.c					\
		ft_toupper.c					\
		ft_tolower.c					\
		ft_strchr.c						\
		ft_strrchr.c					\
		ft_strncmp.c					\
		ft_memchr.c						\
		ft_strnstr.c					\
		ft_atoi.c						\
		ft_calloc.c						\
		ft_strdup.c						\
		ft_substr.c						\
		ft_strjoin.c					\
		ft_split.c						\
		ft_strtrim.c					\
		ft_putchar_fd.c					\
		ft_striteri.c					\
		ft_strmapi.c					\
		ft_itoa.c						\
		ft_putstr_fd.c					\
		ft_putendl_fd.c					\
		ft_putnbr_fd.c					\
		ft_memcmp.c						\
		ft_printf.c						\
		ft_printstr.c					\
		ft_printchar.c					\
		ft_printnbr.c					\
		ft_printptr.c					\
		get_next_line_bonus.c 			\
		get_next_line_utils_bonus.c

SRCS_B =	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

CC = cc

CFLAGS = -Wall -Wextra -Werror

DEPS = libft.h

RM = rm - f

AR = ar -rc

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $(OBJS) $(OBJS_B)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJS) $(OBJS_B) $(OBJS_PRINTF)

fclean: clean
	rm -f $(NAME)

##########################################################
nettoyer:
	clear

exec_blabla:
	@echo "Execution du fichier test :"

compiltest:
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_B) -o test

exec_test: exec_blabla
	@./test

supr_blabla:
	@echo "Supression du fichier test"

supr_test: supr_blabla
	@rm -f test

test: nettoyer compiltest exec_test supr_test

norm: nettoyer
	norminette
##########################################################

re: fclean all

so:
		$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
		gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re bonus
