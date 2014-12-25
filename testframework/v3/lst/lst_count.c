/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/25 20:09:56 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

size_t		lst_count(t_lst *lst, void *(*f)(void *))
{
	int			len;
	t_lst_elem	*elem;

	len = 0;
	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data))
			len++;
		elem = elem->next;
	}
	return (len);
}
