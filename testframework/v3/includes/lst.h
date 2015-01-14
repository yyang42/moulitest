/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/12 17:06:40 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stddef.h>

typedef struct			s_lst_elem
{
	void				*data;
	struct s_lst_elem	*next;
	struct s_lst_elem	*prev;
	struct s_lst		*parent;
	char				*key;
}						t_lst_elem;

typedef struct			s_lst
{
	size_t				len;
	struct s_lst_elem	*elems;
}						t_lst;

t_lst					*lst_init(void);
t_lst_elem				*lst_create_elem(void *data);
void					lst_push(t_lst *lst, t_lst_elem *newelem);
void					lst_pop(t_lst *lst);
size_t					lst_len(t_lst *lst);
t_lst_elem				*lst_get(t_lst *lst, size_t index);
void					lst_unshift(t_lst *lst, t_lst_elem *elem);
t_lst					*lst_map(t_lst *lst,
										t_lst_elem *(*f)(t_lst_elem *elem));
void					lst_iter(t_lst *lst, void (*f)(t_lst_elem	*elem));
void					lst_del(t_lst *lst, void (*delfn)());
void					lst_del_elem(t_lst *lst, t_lst_elem *elem,
															void (*delfn)());
void					lstelem_del(t_lst_elem *elem, void (*delfn)());
t_lst_elem				*lst_find(t_lst *lst, void *(*f)(void *));
size_t					lst_count(t_lst *lst, void *(*f)(void *));
void					*lst_reduce(t_lst *lst, void *(*fn)(t_lst_elem *elem,
							void *memo), void *context);
int						lst_reducei(t_lst *lst, int (*fn)(t_lst_elem *elem,
							int memo), int memo);
t_lst_elem				*lst_find_by_value(t_lst *lst,
								int(*f)(void *data, void *value), void *value);

void					lst__link(t_lst_elem *elem1, t_lst_elem *elem2);

#endif
