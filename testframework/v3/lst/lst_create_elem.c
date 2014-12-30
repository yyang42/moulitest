/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:18:33 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 13:08:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

t_lst_elem	*lst_create_elem(void *data)
{
	t_lst_elem *elem;

	elem = (t_lst_elem *)malloc(sizeof(t_lst_elem));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	elem->parent = NULL;
	return (elem);
}
