# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbump <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 18:13:34 by sbump             #+#    #+#              #
#    Updated: 2020/07/16 21:18:56 by sbump            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

OBJ = $(SRC:.c=.o)

SRC_LIBFT = LIBFT/*.c

DIR_LIB = LIBFT/

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

ALL_OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) $(SRC_LIBFT)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	make -C $(DIR_LIB) fclean
	/bin/rm -f $(ALL_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
