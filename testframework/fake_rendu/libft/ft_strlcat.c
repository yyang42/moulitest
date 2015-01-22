/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/09 21:00:00 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dest_cpy;
	char	*src_cpy;
	size_t	size_cpy;
	size_t	lenght;

	dest_cpy = dst;
	src_cpy = (char *)src;
	size_cpy = size;
	while (*dest_cpy != '\0' && size_cpy-- != 0)
		dest_cpy++;
	lenght = dest_cpy - dst;
	size_cpy = size - lenght;
	if (size_cpy == 0)
		return (lenght + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (size_cpy != 1)
		{
			*dest_cpy++ = *src_cpy;
			size_cpy--;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (lenght + (src_cpy - src));
}
