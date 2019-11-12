# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2013/12/26 20:53:30 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ./libft/
LIBA = $(DIR)libft.a
SRC = ms1.c
SRC += ft_exec.c
SRC += ft_cd.c
SRC += ft_setenv.c
OBJET = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJET) $(LIBA)
	$(CC) -o $@ $^ $(CFLAGS)

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
