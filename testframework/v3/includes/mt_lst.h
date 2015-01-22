/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:27:41 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_LST_H
# define MT_LST_H
# include <stddef.h>

typedef struct			s_mt_lst_elem
{
	void				*data;
	struct s_mt_lst_elem	*next;
	struct s_mt_lst_elem	*prev;
	struct s_mt_lst		*parent;
	char				*key;
}						t_mt_lst_elem;

typedef struct			s_mt_lst
{
	size_t				len;
	struct s_mt_lst_elem	*elems;
}						t_mt_lst;

t_mt_lst					*mt_lst_init(void);
t_mt_lst_elem				*mt_lst_create_elem(void *data);
void					mt_lst_push(t_mt_lst *lst, t_mt_lst_elem *newelem);
void					mt_lst_pop(t_mt_lst *lst);
size_t					mt_lst_len(t_mt_lst *lst);
t_mt_lst_elem				*mt_lst_get(t_mt_lst *lst, size_t index);
t_mt_lst					*mt_lst_map(t_mt_lst *lst,
										t_mt_lst_elem *(*f)(t_mt_lst_elem *elem));
void					mt_lst_iter(t_mt_lst *lst, void (*f)(t_mt_lst_elem	*elem));
void					mt_lst_del(t_mt_lst *lst, void (*delfn)());
void					mt_lst_del_elem(t_mt_lst *lst, t_mt_lst_elem *elem,
															void (*delfn)());
void					mt_lstelem_del(t_mt_lst_elem *elem, void (*delfn)());
t_mt_lst_elem				*mt_lst_find(t_mt_lst *lst, void *(*f)(void *));
size_t					mt_lst_count(t_mt_lst *lst, void *(*f)(void *));
int						mt_lst_reducei(t_mt_lst *lst, int (*fn)(t_mt_lst_elem *elem,
							int memo), int memo);
void					mt_lst__link(t_mt_lst_elem *elem1, t_mt_lst_elem *elem2);

#endif
