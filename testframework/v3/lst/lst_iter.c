/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 11:03:53 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_iter(t_lst *lst, void (*f)(t_lst_elem *elem))
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		f(elem);
		elem = elem->next;
	}
}
