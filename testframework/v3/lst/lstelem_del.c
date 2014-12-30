/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstelem_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 13:31:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

#include <stdio.h>

void	lstelem_del(t_lst_elem *elem, void (*delfn)())
{
	delfn(elem->data);
	elem->data = NULL;
	free(elem);
}
