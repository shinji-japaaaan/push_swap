# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 11:08:06 by sishizaw          #+#    #+#              #
#    Updated: 2024/08/18 20:22:18 by sishizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
SRC = main.c \
	  sort.c \
	  operations_1.c \
	  operations_2.c \
	  operations_3.c \
	  utils_apply.c \
	  utils_case_ab.c \
	  utils_case_ba.c \
	  utils_check.c \
	  utils_find.c \
	  utils_input.c \
	  utils_libft1.c \
	  utils_libft2.c \
	  utils_other.c \
	  utils_get_costinfo.c \

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