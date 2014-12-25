/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/25 21:34:40 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

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
