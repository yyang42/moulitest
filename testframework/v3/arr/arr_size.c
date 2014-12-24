/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:23:16 by yyang             #+#    #+#             */
/*   Updated: 2014/12/24 19:42:37 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	arr_size(void *arr)
{
	size_t	size;
	long	*l_arr;

	l_arr = (long *)arr;
	size = 0;
	while (l_arr[size])
		size++;
	return (size);
}
