/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 15:44:37 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/29 18:01:42 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				i;
	struct s_list	*next;
}					t_list;

/*
** LIST_C
*/

t_list	*ft_new(int i);
void	ft_del(t_list **lst);
void	ft_push(t_list **lst, t_list *new);
t_list	*ft_pull(t_list **lst);
t_list	*ft_last(t_list *lst);

/*
** PROCESS_C
*/

void	ft_swap(t_list **lst);
void	ft_lr(t_list **lst, t_list **last);
void	ft_rr(t_list **lst, t_list **last);

/*
** UTILITIES_C
*/

int		ft_atoi(const char *str);
int		is_sorted(t_list *lst);
int		is_max(t_list *lst, t_list *elem);
int		is_allmax(t_list *l1, t_list *l2);

#endif
