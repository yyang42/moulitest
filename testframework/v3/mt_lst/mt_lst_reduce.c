/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/02 23:45:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

void					*mt_lst_reduce(t_mt_lst *lst, void *(*fn)(t_mt_lst_elem *elem,
							void *memo), void *context)
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		context = fn(elem, context);
		elem = elem->next;
	}
	return (context);
}
