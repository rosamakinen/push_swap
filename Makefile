# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:13:01 by rmakinen          #+#    #+#              #
#    Updated: 2023/03/02 11:30:32 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = -I push_swap.h
SRC_DIR = ./
FILES = push_swap checks swap sort rotate push
SRC = $(addprefix $(SRC_DIR),$(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(SRC_DIR),$(addsuffix .o, $(FILES)))
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRC)
	@cd libft && $(MAKE)
	@cc -o $(NAME) $(FLAGS) $(SRC) -L. ./libft/libft.a

clean:
	cd libft && make clean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
