/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:36:57 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:13:13 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t lenght;
	size_t index;

	if (!s)
		return ;
	lenght = ft_strlen(s);
	index = 0;
	while (index < lenght)
	{
		s[index++] = '\0';
	}
}
