/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 10:56:38 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*cpy;
	char	*buf;
	size_t	lenght;

	buf = (char *)(s1 + n);
	lenght = ft_strlen(s2);
	cpy = (char *)s1;
	if (!s1 || !s2 || !lenght)
		return ((char *)s1);
	while ((cpy = ft_strchr(cpy, *s2)) && cpy <= buf)
	{
		if ((cpy + lenght <= buf) && !ft_strncmp(cpy, s2, lenght))
			return (cpy);
		cpy++;
	}
	return (NULL);
}
