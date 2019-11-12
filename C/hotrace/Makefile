# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 20:10:15 by jquilez           #+#    #+#              #
#    Updated: 2013/12/15 19:21:47 by jquilez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#General
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

#Messages
MSG_OBJ		= @echo "\033[33m[object] " | tr -d '\n'
MSG_BUILD	= @echo "\033[32m[build]  " | tr -d '\n'
MSG_DELETE	= @echo "\033[31m[delete] " | tr -d '\n'
MSG_CLOSE	= @echo "\033[0m" | tr -d '\n'

#Files
NAME		= hotrace
SRC			= hotrace.c
SRC			+= hr_btree.c
SRC			+= hr_gnl.c
SRC			+= hr_put.c
SRC			+= hr_rotate.c
SRC			+= hr_str.c
SRC			+= hr_str2.c
SRC			+= hr_clean.c
OBJET		= $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJET)
	$(MSG_BUILD)
	$(CC) -o $(NAME) $(OBJET)$(CFLAGS)
	$(MSG_CLOSE)

%.o: %.c
	$(MSG_OBJ)
	$(CC) -o $@ -c $< $(CFLAGS)
	$(MSG_CLOSE)

clean:
	$(MSG_DELETE)
	/bin/rm -f $(OBJET)
	$(MSG_CLOSE)

fclean: clean
	$(MSG_DELETE)
	/bin/rm -f $(NAME)
	$(MSG_CLOSE)

re: fclean all
