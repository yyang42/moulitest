/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/26 17:09:39 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

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
