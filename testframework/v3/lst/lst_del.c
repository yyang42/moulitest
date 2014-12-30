/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 13:31:16 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

void	lst_del(t_lst *lst, void (*delfn)(void *))
{
	t_lst_elem *elem;

	elem = lst->elems;
	while (elem)
	{
		lstelem_del(elem, delfn);
		elem = elem->next;
	}
	free(lst);
}
