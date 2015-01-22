/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:08:26 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 17:41:32 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*cpy;
	size_t	index;

	cpy = dst;
	index = 0;
	while (src[index] != '\0')
	{
		cpy[index] = src[index];
		index++;
	}
	cpy[index] = '\0';
	return (dst);
}
