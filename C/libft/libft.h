/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:47:43 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/24 22:01:07 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

/*
** MEMORY MANIPULATION
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

/*
** STRINGS MANIPULATION
*/

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strrev(char *str);
int		ft_nb_ws(char *str);
void	ft_ptrstrdel(char ***ptr);
char	**ft_ptrstrstr(char **ptr, char *s);
char	**ft_ptrstrdup(char **ptr);
char	**ft_ptrstrsub(char **ptr, int start, int len);

/*
** DATA CHECK
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_islower(char *str);
int		ft_isupper(char *str);

/*
** DATA DISPLAY
*/

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putptrstr(char **s);

/*
** LISTS
*/

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t	ft_lstlen(t_list *lst);
t_list	*ft_strsplitlst(char const *s, char c);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_merge(t_list **begin_list1, t_list **begin_list2);
void	ft_list_push_back(t_list **begin_list, void *data, size_t size);
t_list	*ft_list_push_params(int ac, char **av);
void	ft_list_reverse(t_list **begin_list);
t_list	*ft_lstpush(t_list *top, void const *c, size_t s);
void	*ft_lstpull(t_list **top);

/*
** MATH
*/

int		ft_is_prime(int nb);
int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_sqrt(int nb);
void	ft_swap(int *a, int *b);
int		ft_max(int a, int b);

/*
** TREES
*/

t_btree	*btree_create_node(void const *content, size_t content_size);
void	btree_insert(t_btree **t, void *c, size_t s, \
			int (*cmp)(void *, void *));
t_btree	*btree_search(t_btree *t, void *c, int (*cmp)(void *, void*));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *, size_t));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *, size_t));
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *, size_t));

#endif
