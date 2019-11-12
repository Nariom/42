# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:38:58 by rbaudot           #+#    #+#              #
#    Updated: 2014/01/24 22:01:40 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c
SRC += ft_bzero.c
SRC += ft_memcpy.c
SRC += ft_memccpy.c
SRC += ft_memmove.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_strlen.c
SRC += ft_strdup.c
SRC += ft_strcpy.c
SRC += ft_strncpy.c
SRC += ft_strcat.c
SRC += ft_strncat.c
SRC += ft_strlcat.c
SRC += ft_strchr.c
SRC += ft_strrchr.c
SRC += ft_strstr.c
SRC += ft_strnstr.c
SRC += ft_strcmp.c
SRC += ft_strncmp.c
SRC += ft_atoi.c
SRC += ft_isalpha.c
SRC += ft_isdigit.c
SRC += ft_isalnum.c
SRC += ft_isascii.c
SRC += ft_isprint.c
SRC += ft_toupper.c
SRC += ft_tolower.c
SRC += ft_memalloc.c
SRC += ft_memdel.c
SRC += ft_strnew.c
SRC += ft_strdel.c
SRC += ft_strclr.c
SRC += ft_striter.c
SRC += ft_striteri.c
SRC += ft_strmap.c
SRC += ft_strmapi.c
SRC += ft_strequ.c
SRC += ft_strnequ.c
SRC += ft_strsub.c
SRC += ft_strjoin.c
SRC += ft_strtrim.c
SRC += ft_strsplit.c
SRC += ft_itoa.c
SRC += ft_putchar.c
SRC += ft_putstr.c
SRC += ft_putendl.c
SRC += ft_putnbr.c
SRC += ft_putchar_fd.c
SRC += ft_putstr_fd.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_lstlen.c
SRC += ft_strsplitlst.c
SRC += ft_list_at.c
SRC += ft_list_find.c
SRC += ft_list_last.c
SRC += ft_list_merge.c
SRC += ft_list_push_back.c
SRC += ft_list_push_params.c
SRC += ft_list_reverse.c
SRC += ft_lstpush.c
SRC += ft_lstpull.c
SRC += ft_is_prime.c
SRC += ft_factorial.c
SRC += ft_power.c
SRC += ft_sqrt.c
SRC += ft_islower.c
SRC += ft_isupper.c
SRC += ft_swap.c
SRC += ft_strrev.c
SRC += btree_create_node.c
SRC += btree_insert.c
SRC += btree_search.c
SRC += btree_apply_infix.c
SRC += btree_apply_suffix.c
SRC += btree_apply_prefix.c
SRC += ft_nb_ws.c
SRC += ft_max.c
SRC += ft_ptrstrdel.c
SRC += ft_putptrstr.c
SRC += ft_ptrstrstr.c
SRC += ft_ptrstrdup.c
SRC += ft_ptrstrsub.c
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
