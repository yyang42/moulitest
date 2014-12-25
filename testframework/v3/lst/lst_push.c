/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2014/12/12 18:20:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

void	lst_push(t_lst *lst, void *data)
{
	t_lst_elem *elem;

	if (!lst->elems)
	{
		lst->elems = lst_create_elem(lst, data);
	}
	else
	{
		elem = lst->elems;
		while (elem->next)
			elem = elem->next;
		elem->next = lst_create_elem(lst, data);
		lst__link(elem, elem->next);
	}
}
