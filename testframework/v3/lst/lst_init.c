/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:45:21 by yyang             #+#    #+#             */
/*   Updated: 2014/12/12 10:15:16 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

t_lst	*lst_init(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->len = 0;
	lst->elems = NULL;
	return (lst);
}
