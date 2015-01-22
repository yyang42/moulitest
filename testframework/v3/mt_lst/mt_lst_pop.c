/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:23:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

void	mt_lst_pop(t_mt_lst *lst)
{
	t_mt_lst_elem *elem;
	t_mt_lst_elem *prev;

	elem = lst->elems;
	while (elem->next)
		elem = elem->next;
	prev = elem->prev;
	if (lst->elems == elem)
		lst->elems = NULL;
	if (prev)
		prev->next = NULL;
}
