/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 09:48:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

size_t	mt_lst_len(t_mt_lst *lst)
{
	int			len;
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	len = 0;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}
