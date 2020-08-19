# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbump <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 18:13:34 by sbump             #+#    #+#              #
#    Updated: 2019/09/29 17:30:51 by sbump            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_isprint.c ./ft_memmove.c ./ft_strdel.c ./ft_strnew.c ./ft_atoi.c ./ft_memalloc.c ./ft_memset.c ./ft_strdup.c ./ft_strnstr.c ./ft_bzero.c ./ft_memccpy.c ./ft_strcat.c ./ft_strlcat.c ./ft_strrchr.c ./ft_isalnum.c ./ft_memchr.c ./ft_strchr.c ./ft_strlen.c ./ft_strstr.c ./ft_isalpha.c ./ft_memcmp.c ./ft_strclr.c ./ft_strncat.c ./ft_tolower.c ./ft_isascii.c ./ft_memcpy.c ./ft_strcmp.c ./ft_strncmp.c ./ft_toupper.c ./ft_isdigit.c ./ft_memdel.c ./ft_strcpy.c ./ft_strncpy.c ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c

HDR = ./

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HDR) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
