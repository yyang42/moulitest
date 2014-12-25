/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2014/12/19 11:59:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>
#include <stdlib.h>

void	lst_del_elem(t_lst *lst, t_lst_elem *elem)
{
	free(elem->data);
	elem->data = NULL;
	free(elem);
	elem = NULL;
	(void)lst;
}
