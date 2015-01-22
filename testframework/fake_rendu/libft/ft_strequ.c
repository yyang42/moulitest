/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:38:46 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:16:49 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
			return (1);
		index++;
	}
	return (0);
}
