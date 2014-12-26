/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/26 17:42:03 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>

int		ft_printf(const char *format, ...);
char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

#define	assert_printf(format, ...) assert(strcmp(ft_printf_to_str(#format, ## __VA_ARGS__), printf_to_str(#format, ## __VA_ARGS__)) == 0)

// #define UT_PRINTF_ASSERT(string, ...)

// void	assert_printf(char *format, ...)
// {
// 	char *s;
//     va_list args;

//     va_start(args, format);
	
//     va_end(args);
// }

// #define UT_PRINTF_ASSERT(string, ...)	fflush(stdout);						\
// 										old_out = dup(1);					\
// 										pipe(p);							\
// 										dup2(p[1], 1);						\
// 										ret1 = printf(string, __VA_ARGS__);	\
// 										dup2(old_out, 1);					\
// 										out1[read(p[0], out1, sizeof(out1) - 1)] = 0; \
// 										close(p[1]);						\
// 										close(p[0]);						\
// 										close(old_out);						\
// 																			\
// 										old_out = dup(1);					\
// 										pipe(p);							\
// 										dup2(p[1], 1);						\
// 										ret2 = ft_printf(string, __VA_ARGS__); \
// 										dup2(old_out, 1);					\
// 										out2[read(p[0], out2, sizeof(out2) - 1)] = 0; \
// 										close(p[1]);						\
// 										close(p[0]);						\
// 										close(old_out);						\
// 																			\
// 										UT_ASSERT(ret1 == ret2 && strcmp(out1, out2) == 0);
										

#endif
