NAME = ft_ls

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C FT_PRINTF/
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror $(OBJ) FT_PRINTF/libftprintf.a -o ft_ls

clean:
	make -C FT_PRINTF/ fclean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
