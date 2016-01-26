# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/01/26 14:59:50 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = Libft/libft.a

SRC =	chr.c\
		main.c\
		pos.c\
		print_solution.c\
		range_min.c\
		read.c\
		solution_cpy.c\
		solve.c\
		validity.c\

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C Libft
	gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

clean:
	make -C Libft clean

fclean: clean
	make -C Libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
