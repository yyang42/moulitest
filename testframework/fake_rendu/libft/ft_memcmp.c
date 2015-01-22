/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 10:49:28 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*cpys1;
	unsigned char	*cpys2;

	index = 0;
	cpys1 = (unsigned char *)s1;
	cpys2 = (unsigned char *)s2;
	while (index < n)
	{
		if (cpys1[index] != cpys2[index])
			return (cpys1[index] - cpys2[index]);
		index++;
	}
	return (0);
}
