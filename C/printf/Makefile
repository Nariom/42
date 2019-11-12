# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2013/12/22 19:09:03 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = llvm-gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
SRC += ft_convert.c
SRC += ft_flag.c
SRC += ft_is.c
SRC += ft_part.c
SRC += ft_put.c
SRC += ft_str.c
SRC += ft_utilities.c
OBJET = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJET)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(OBJET)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
