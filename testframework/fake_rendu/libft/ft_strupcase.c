/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:27:08 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/11 11:41:13 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	int index;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index] != '\0')
	{
		if (ft_islower(str[index]))
			str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}
