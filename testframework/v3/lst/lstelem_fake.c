/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstelem_fake.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/20 22:40:07 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mt_lst.h>
#include <stdlib.h>

void	lstelem_fake(t_lst_elem *elem, void (*delfn)())
{
	(void)elem;
	(void)delfn;
}
