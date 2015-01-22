/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstelem_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 20:43:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

void	mt_lstelem_del(t_mt_lst_elem *elem, void (*delfn)())
{
	delfn(elem->data);
	if (elem->key)
		free(elem->key);
	elem->data = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	elem->parent = NULL;
	elem->key = NULL;
	free(elem);
}
