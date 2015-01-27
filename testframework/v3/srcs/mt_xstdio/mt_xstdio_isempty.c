/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_xstdio_isempty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 22:16:18 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 10:28:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int mt_isemptyfile(const char *path)
{
	FILE *fp;

	fp = fopen(path, "r");
	long saved_offset = ftell(fp);
	fseek(fp, 0, SEEK_END);

	if (ftell(fp) == 0)
		return (1);
	fseek(fp, saved_offset, SEEK_SET);
	fclose(fp);
	return (0);
}