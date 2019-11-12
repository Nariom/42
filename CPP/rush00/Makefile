#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:44:39 by jmaurice          #+#    #+#              #
#    Updated: 2015/01/10 16:59:10 by rbaudot          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = g++
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -lncurses
INC =
FILES = AMoving AShip Missile Player AEnemy Boss Grunt Game.class main
SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
NAME = ft_retro

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $^ $(INC)

debug: clean
	$(CC) -o $@ -g -Wall -Wextra $(SRC) $(INC) $(LDFLAGS)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f debug

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
