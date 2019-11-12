# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2013/12/18 18:14:39 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/usr/X11/lib -lmlx -lXext -lX11
DIR = ./libft/
LIBA = $(DIR)libft.a
SRC = fdf.c
SRC += ft_file_split.c
SRC += ft_display_file.c
SRC += ft_draw.c
SRC += ft_utilities.c
OBJET = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJET) $(LIBA)
	$(CC) -o $@ $^ $(MLX) $(CFLAGS)

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
