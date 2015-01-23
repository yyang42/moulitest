/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:22:05 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

t_mt_lst		*mt_lst_map(t_mt_lst *lst, t_mt_lst_elem *(*fn)(t_mt_lst_elem *elem))
{
	t_mt_lst		*new_lst;
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	new_lst = mt_lst_init();
	while (elem)
	{
		mt_lst_push(new_lst, fn(elem));
		elem = elem->next;
	}
	return (new_lst);
}
