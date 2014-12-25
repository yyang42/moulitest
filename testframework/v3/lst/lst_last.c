/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2014/12/25 22:55:38 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>

t_lst_elem		*lst_last(t_lst *lst)
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
