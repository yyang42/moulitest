/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:54:47 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/09 18:47:52 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(char *str, char change, char new_c)
{
	char	*cpy;
	int		index;

	cpy = (char *)ft_memalloc(ft_strlen(str) + 1);
	cpy = str;
	index = 0;
	while (cpy[index] != '\0')
	{
		if (cpy[index] == change)
			cpy[index] = new_c;
		index++;
	}
	return (cpy);
}
