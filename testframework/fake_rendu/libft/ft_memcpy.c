/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 11:16:58 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	index;
	char			*destcpy;
	char			*srccpy;

	destcpy = dst;
	srccpy = (char *)src;
	index = 0;
	while (index < n)
	{
		destcpy[index] = srccpy[index];
		index++;
	}
	return (destcpy);
}
