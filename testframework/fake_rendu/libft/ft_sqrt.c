/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:00:00 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/09 14:22:02 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(int nb)
{
	int index;

	index = nb;
	if (nb < 0)
		return (0);
	while (nb < (index * index))
	{
		index--;
	}
	if (nb == (index * index))
	{
		return (index);
	}
	else
		return (0);
}
