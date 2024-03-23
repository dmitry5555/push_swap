# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 18:32:22 by dlariono          #+#    #+#              #
#    Updated: 2023/06/28 17:45:01 by dlariono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRC = $(shell find src -name '*.c')
INC = ./inc/push_swap.h ./inc/push_swap2.h

OBJ = ${SRC:.c=.o}

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo "${NAME} ✔️"
			@echo "mandatory files compiled successfully ✔️"

%.o:	%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

clean:
	${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	clean all

.PHONY: all clean fclean re
  