/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:09:13 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/14 18:10:43 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_realloc(void *ptr, size_t size)
{
	void			*cpy;

	cpy = ft_memalloc(size);
	if (ptr)
	{
		if (cpy)
			ft_memcpy(cpy, ptr, size);
		ft_memdel(&ptr);
	}
	return (cpy);
}
