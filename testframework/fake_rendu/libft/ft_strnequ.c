/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:41:58 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:17:17 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	if (!s1 || !s2)
		return (0);
	index = 0;
	while (index < n)
	{
		if (s1[index] == s2[index])
			index++;
		else if (s1[index] != s2[index])
			return (0);
	}
	return (1);
}
