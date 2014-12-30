/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2014/12/12 16:39:24 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst_elem	*lst_get(t_lst *lst, size_t index)
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem && index--)
		elem = elem->next;
	return (elem ? elem : NULL);
}
