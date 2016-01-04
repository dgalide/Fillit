NAME = fillit

SRC =	src/main.c \
	 	src/read.c \
		src/clean.c \
		src/map.c \
		src/fillit.c \
		src/functions.c

LIB = inc/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm fillit

re: fclean all

$(NAME):
	$(CC) -o fillit $(CFLAGS) $(SRC) $(LIB)

.PHONY: all re clean fclean
