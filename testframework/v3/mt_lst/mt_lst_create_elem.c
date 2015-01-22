/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_create_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:18:33 by yyang             #+#    #+#             */
/*   Updated: 2015/01/09 15:07:34 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

t_mt_lst_elem	*mt_lst_create_elem(void *data)
{
	t_mt_lst_elem *elem;

	elem = (t_mt_lst_elem *)malloc(sizeof(t_mt_lst_elem));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	elem->parent = NULL;
	elem->key = NULL;
	return (elem);
}
