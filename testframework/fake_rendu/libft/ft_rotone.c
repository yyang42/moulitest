/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:17:43 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 17:38:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	rot_char(char c)
{
	if (c >= 'a' && c < 'z')
		return (c + 1);
	else if (c == 'z' || c == 'Z')
		return (c - 25);
	else if (c >= 'A' && c < 'Z')
		return (c + 1);
	return (c);
}

char		*rotone(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = rot_char(str[i]);
		i++;
	}
	return (str);
}
