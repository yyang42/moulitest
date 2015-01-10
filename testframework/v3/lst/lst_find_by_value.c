/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_by_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/08 20:15:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst_elem		*lst_find_by_value(t_lst *lst,
							int (*f)(void *data, void *value), void *value)
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data, value))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
