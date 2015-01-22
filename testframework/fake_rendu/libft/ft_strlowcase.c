/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:39:53 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/11 11:41:08 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int index;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index] != '\0')
	{
		if (ft_isupper(str[index]))
			str[index] = ft_tolower(str[index]);
		index++;
	}
	return (str);
}
