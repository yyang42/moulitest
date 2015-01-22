/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:16:49 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:15:12 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;
	size_t	index;

	if (!s || !f)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s));
	index = 0;
	while (s[index] != '\0')
	{
		cpy[index] = (*f)(s[index]);
		index++;
	}
	return (cpy);
}
