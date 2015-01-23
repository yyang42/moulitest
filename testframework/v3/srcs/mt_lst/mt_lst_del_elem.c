/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:07:44 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

void	mt_lst_del_elem(t_mt_lst *lst, t_mt_lst_elem *elem, void (*delfn)())
{
	if (lst->elems == elem)
		lst->elems = elem->next;
	mt_lst__link(elem->prev, elem->next);
	delfn(elem->data);
	if (elem->key)
		free(elem->key);
	elem->data = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	elem->parent = NULL;
	elem->key = NULL;
	free(elem);
	(void)lst;
}
