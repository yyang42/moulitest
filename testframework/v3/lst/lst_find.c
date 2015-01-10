/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/08 19:44:29 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst_elem		*lst_find(t_lst *lst, void *(*f)(void *))
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
