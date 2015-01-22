/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:33:11 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:15:36 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s));
	index = 0;
	while (s[index] != '\0')
	{
		cpy[index] = (*f)(index, s[index]);
		index++;
	}
	return (cpy);
}
