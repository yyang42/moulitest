/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:38:02 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 15:01:06 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(t_list *elem))
{
	t_list *list;

	if (lst)
	{
		list = lst;
		while (list)
		{
			f(list);
			list = list->next;
		}
	}
}
