/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:00:24 by juschaef          #+#    #+#             */
/*   Updated: 2014/11/08 20:46:11 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_str(int nbr, int index)
{
	while (nbr > 9 || nbr < 0)
	{
		index++;
		nbr /= 10;
	}
	return (index);
}

char		*ft_itoa(int n)
{
	char	*str_ret;
	char	*str_prov;
	int		sign;
	int		nbr;
	int		index;

	sign = (n < 0) ? 2 : 1;
	nbr = n;
	index = ft_size_str(n, sign);
	str_prov = ft_strnew(index + 1);
	while (index > 0)
	{
		if (n >= 0)
			str_prov[index - 1] = ((char)((nbr % 10) + 48));
		if (n < 0 && index >= 2)
			str_prov[index - 2] = ((char)(48 - (nbr % 10)));
		index--;
		nbr /= 10;
	}
	if (n < 0)
		str_prov[index] = '-';
	str_ret = ft_strnew(ft_size_str(n, sign) + 1);
	ft_strcpy(str_ret, str_prov);
	return (str_ret);
}
