/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_reducei.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/04 19:35:01 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

int mt_lst_reducei(t_mt_lst *lst, int (*fn)(t_mt_lst_elem *elem, int memo), int memo)
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		memo = fn(elem, memo);
		elem = elem->next;
	}
	return (memo);
}
