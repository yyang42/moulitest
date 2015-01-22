/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 10:49:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	destcpy = dst;
	srccpy = src;
	while (n--)
	{
		if (*srccpy == c)
		{
			*destcpy++ = *srccpy++;
			return (destcpy);
		}
		*destcpy++ = *srccpy++;
	}
	return (NULL);
}
