/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 12:37:31 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_push(t_lst *lst, t_lst_elem *newelem)
{
	t_lst_elem *tmpelem;

	newelem->parent = lst;
	if (!lst->elems)
	{
		lst->elems = newelem;
	}
	else
	{
		tmpelem = lst->elems;
		while (tmpelem->next)
			tmpelem = tmpelem->next;
		tmpelem->next = newelem;
		lst__link(tmpelem, tmpelem->next);
	}

}
