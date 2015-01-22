/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:48:35 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 21:02:38 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	index;

	if (!s)
		return (NULL);
	if (!(cpy = ft_strnew(len + 1)))
		return (NULL);
	index = 0;
	while (index < len)
	{
		cpy[index] = s[start];
		index++;
		start++;
	}
	return (cpy);
}
