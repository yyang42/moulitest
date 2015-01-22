/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:10:06 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/09 18:48:45 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *s1, void *s2, size_t size)
{
	void *temp;

	temp = ft_memalloc(size);
	ft_memcpy(temp, s1, size);
	ft_memcpy(s1, s2, size);
	ft_memcpy(s2, temp, size);
	free(temp);
}
