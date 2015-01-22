/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/08 19:44:29 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

t_mt_lst_elem		*mt_lst_find(t_mt_lst *lst, void *(*f)(void *))
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
