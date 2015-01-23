/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_find_by_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/08 20:15:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

t_mt_lst_elem		*mt_lst_find_by_value(t_mt_lst *lst,
							int (*f)(void *data, void *value), void *value)
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data, value))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
