/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/22 22:23:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

t_mt_lst_elem	*mt_lst_get(t_mt_lst *lst, size_t index)
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem && index--)
		elem = elem->next;
	return (elem ? elem : NULL);
}
