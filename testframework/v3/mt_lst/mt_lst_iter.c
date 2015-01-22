/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:06:30 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/20 22:44:46 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>

void	mt_lst_iter(t_mt_lst *lst, void (*f)(t_mt_lst_elem *elem))
{
	t_mt_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		f(elem);
		elem = elem->next;
	}
}
