/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:13:13 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 22:01:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nb_array(char const *s, char c)
{
	size_t nbr;
	size_t index;

	nbr = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index])
		{
			index++;
			nbr++;
			while (s[index] != c && s[index])
				index++;
		}
	}
	return (nbr);
}

static char			*ft_put_array(size_t *index, char const *s, char c)
{
	size_t	size;
	size_t	index_2;
	char	*array;

	size = *index;
	index_2 = 0;
	while (s[size] && s[size] != c)
		size++;
	array = ft_strnew(size - *index);
	if (array)
	{
		while (*index < size)
		{
			array[index_2] = s[*index];
			index_2++;
			*index += 1;
		}
		return (array);
	}
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**grid;
	size_t	index;
	size_t	index_2;

	index = 0;
	index_2 = 0;
	grid = NULL;
	if (s)
		grid = (char **)ft_memalloc(sizeof(char *) * ft_nb_array(s, c) + 1);
	if (grid)
	{
		while (index_2 < ft_nb_array(s, c))
		{
			while (s[index] == c)
				index++;
			if (s[index] != c && s[index])
				grid[index_2++] = ft_put_array(&index, s, c);
		}
		grid[index_2] = 0;
		return (grid);
	}
	return (0);
}
