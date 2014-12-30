/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 14:39:53 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		*lst_map(t_lst *lst, t_lst_elem *(*fn)(t_lst_elem *elem))
{
	t_lst		*new_lst;
	t_lst_elem	*elem;

	elem = lst->elems;
	new_lst = lst_init();
	while (elem)
	{
		lst_push(new_lst, fn(elem));
		elem = elem->next;
	}
	return (new_lst);
}
