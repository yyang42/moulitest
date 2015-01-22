/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:33:50 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/07 11:21:45 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index_1;
	int index_2;

	index_1 = 0;
	index_2 = 0;
	while (s1[index_1] != '\0')
		index_1++;
	while (s2[index_2] != '\0')
	{
		s1[index_1 + index_2] = s2[index_2];
		index_2++;
	}
	s1[index_1 + index_2] = '\0';
	return (s1);
}
