/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 13:16:51 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

void	lst_pop(t_lst *lst)
{
	t_lst_elem *elem;
	t_lst_elem *prev;

	elem = lst->elems;
	while (elem->next)
		elem = elem->next;
	prev = elem->prev;
	// lst_del_elem(lst, elem);
	if (lst->elems == elem)
		lst->elems = NULL;
	if (prev)
		prev->next = NULL;
}
