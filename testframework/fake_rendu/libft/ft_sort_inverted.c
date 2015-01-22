/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_inverted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 11:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/02 21:34:27 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_inverted(char **tab, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(tab[j + 1], tab[j]) > 0)
			{
				temp = (char *)ft_strnew(ft_strlen(tab[j + 1] + 1));
				temp = ft_strdup(tab[j + 1]);
				tab[j + 1] = ft_strdup(tab[j]);
				tab[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
}
