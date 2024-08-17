# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 11:08:06 by sishizaw          #+#    #+#              #
#    Updated: 2024/08/17 15:38:30 by sishizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
SRC = srcs/main.c \
	  srcs/sort.c \
	  srcs/operations_1.c \
	  srcs/operations_2.c \
	  srcs/operations_3.c \
	  srcs/utils_apply.c \
	  srcs/utils_case_ab.c \
	  srcs/utils_case_ba.c \
	  srcs/utils_check.c \
	  srcs/utils_find.c \
	  srcs/utils_input.c \
	  srcs/utils_libft1.c \
	  srcs/utils_libft2.c \
	  srcs/utils_other.c \
	  srcs/utils_get_costinfo.c \

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re