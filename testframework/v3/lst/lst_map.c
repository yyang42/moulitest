/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/12 15:38:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

t_lst		*lst_map(t_lst *lst, void *(*f)(void *))
{
	t_lst		*new_lst;
	t_lst_elem	*elem;

	elem = lst->elems;
	new_lst = lst_init();
	while (elem)
	{
		lst_push(new_lst, f(elem->data));
		elem = elem->next;
	}
	return (new_lst);
}
