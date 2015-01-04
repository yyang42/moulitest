/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reducei.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/04 19:35:01 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int lst_reducei(t_lst *lst, int (*fn)(t_lst_elem *elem, int memo), int memo)
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		memo = fn(elem, memo);
		elem = elem->next;
	}
	return (memo);
}
