# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2013/12/29 18:06:37 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c
SRC += list.c
SRC += process.c
SRC += utilities.c
OBJET = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJET)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(OBJET)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
