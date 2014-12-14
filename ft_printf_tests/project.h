/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celegran <celegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/14 05:46:15 by celegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <testframework.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>

int		old_out;
int		ret1;
int		ret2;
char	out1[1024];
char	out2[1024];
int		p[2];

int		ft_printf(char *fmt, ...);

#define UT_PRINTF_ASSERT(string, ...)	fflush(stdout);						\
										old_out = dup(1);					\
										pipe(p);							\
										dup2(p[1], 1);						\
										ret1 = printf(string, __VA_ARGS__);	\
										dup2(old_out, 1);					\
										out1[read(p[0], out1, sizeof(out1) - 1)] = 0; \
										close(p[1]);						\
										close(p[0]);						\
										close(old_out);						\
																			\
										old_out = dup(1);					\
										pipe(p);							\
										dup2(p[1], 1);						\
										ret2 = ft_printf(string, __VA_ARGS__); \
										dup2(old_out, 1);					\
										out2[read(p[0], out2, sizeof(out2) - 1)] = 0; \
										close(p[1]);						\
										close(p[0]);						\
										close(old_out);						\
																			\
										UT_ASSERT(ret1 == ret2 && strcmp(out1, out2) == 0);
										

#endif
