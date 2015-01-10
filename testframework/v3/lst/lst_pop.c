/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:26:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

void	lst_pop(t_lst *lst)
{
	t_lst_elem *elem;
	t_lst_elem *prev;

	elem = lst->elems;
	while (elem->next)
		elem = elem->next;
	prev = elem->prev;
	if (lst->elems == elem)
		lst->elems = NULL;
	if (prev)
		prev->next = NULL;
}
