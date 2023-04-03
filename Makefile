# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:13:01 by rmakinen          #+#    #+#              #
#    Updated: 2023/04/01 09:40:53 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = -I push_swap.h
SRC_DIR = ./
FILES = push_swap checks swap sort rotate push mini_sort mini_sort_b big_sort \
		free big_sort_utils bubblesort
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
	cd libft && make fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
