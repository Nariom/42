# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2014/04/16 17:25:46 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR = libft/
LIBA = $(DIR)libft.a
SRC = cmp.c
SRC += dir.c
SRC += display.c
SRC += file.c
SRC += list.c
SRC += ls.c
SRC += parse.c
SRC += sort.c
SRC += utils.c
OBJET = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJET) $(LIBA)
	$(CC) $^ -o $@ $(CFLAGS)

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
