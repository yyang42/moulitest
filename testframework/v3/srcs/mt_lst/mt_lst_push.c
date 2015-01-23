/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:26:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

void	mt_lst_push(t_mt_lst *lst, t_mt_lst_elem *newelem)
{
	t_mt_lst_elem *tmpelem;

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
		mt_lst__link(tmpelem, tmpelem->next);
	}
}
