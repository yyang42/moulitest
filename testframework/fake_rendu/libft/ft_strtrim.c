/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:18:11 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 21:03:42 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isblank_custom(int c)
{
	if (c == 32 || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		index;
	int		index_end;
	char	*new_str;

	if (!s)
		return (NULL);
	index_end = 0;
	index = 0;
	start = 0;
	new_str = ft_strnew(ft_strlen (s));
	while (index < (int)ft_strlen (s))
	{
		if (!start && ft_isblank_custom(s[index]))
			index++;
		else
		{
			start = 1;
			new_str[index_end++] = s[index++];
		}
	}
	while (ft_isblank_custom(new_str[--index_end]))
		new_str[index_end] = '\0';
	return (new_str);
}
