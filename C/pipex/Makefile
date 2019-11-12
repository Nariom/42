# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2013/12/31 20:33:45 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c
SRC += ft_str.c
SRC += ft_str2.c
SRC += ft_str3.c
SRC += ft_ptrstr.c
SRC += ft_exec.c
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
