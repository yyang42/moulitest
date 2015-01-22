/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:05:49 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:48:24 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		index;
	int		count;

	if (!s1 || !s2)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	index = 0;
	count = 0;
	while (s1[count] != '\0')
		cpy[index++] = s1[count++];
	count = 0;
	while (s2[count] != '\0')
		cpy[index++] = s2[count++];
	return (cpy);
}
