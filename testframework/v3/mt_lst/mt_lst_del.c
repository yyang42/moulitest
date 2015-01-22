/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:08:06 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

void	mt_lst_del(t_mt_lst *lst, void (*delfn)(void *))
{
	t_mt_lst_elem *elem;

	elem = lst->elems;
	while (elem)
	{
		mt_lstelem_del(elem, delfn);
		elem = elem->next;
	}
	free(lst);
}
