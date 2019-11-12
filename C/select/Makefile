# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2014/01/06 21:21:55 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ./libft/
LIBA = $(DIR)libft.a
TERMCAP = /usr/lib -ltermcap
SRC = main.c
SRC += single.c
SRC += signals.c
SRC += display.c
SRC += ft_select.c
OBJET = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJET) $(LIBA)
	$(CC) -o $@ $^ -L $(TERMCAP) $(CFLAGS)

$(LIBA):
	$(MAKE) -C $(DIR)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	$(MAKE) $@ -C $(DIR)
	/bin/rm -f $(OBJET)

fclean: clean
	/bin/rm -f $(NAME) $(LIBA)

re: fclean all
