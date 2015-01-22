/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 11:16:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *cpy;

	cpy = ft_memalloc(len);
	cpy = ft_strncpy(cpy, src, len);
	dest = (void *)ft_strncpy(dest, cpy, len);
	ft_strdel(&cpy);
	return (dest);
}
