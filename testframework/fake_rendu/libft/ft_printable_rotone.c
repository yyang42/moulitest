/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable_rotone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:32:36 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/11 11:25:06 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_printable_rotone(char *str)
{
	int index;

	index = 0;
	while (str[index] != 0)
	{
		if (!(ft_isprint(str[index])))
			index++;
		if (str[index] == 126)
			str[index] = 32;
		else
			str[index] += 1;
		index++;
	}
	return (str);
}
