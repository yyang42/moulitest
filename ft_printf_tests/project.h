/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/26 21:45:54 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>

int		ft_printf(const char *format, ...);
char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

// #define	assert_printf(format, ...) assert(strcmp(printf_to_str(format, ## __VA_ARGS__), printf_to_str(format, ## __VA_ARGS__)) == 0)
// #define	assert_printf(format, ...) printf_to_str(format, ## __VA_ARGS__)

typedef struct s_stdout
{
	int	saved_fd;
	int printf_ret;
	int ft_printf_ret;
	char output[1024];
	char printf_out[1024];
	char ft_printf_out[1024];
	int p[2];
}				t_stdout;

t_stdout *g_stdout;

t_stdout *strdout_init(void);
char	*strdout_output(t_stdout *g_stdout);
void	strdout_save_printf_output(t_stdout *g_stdout);
void	strdout_save_ft_printf_output(t_stdout *g_stdout);

#define assert_printf(string, ...) \
			g_stdout = strdout_init(); \
			g_stdout->printf_ret = printf(string, __VA_ARGS__); \
			strdout_save_printf_output(g_stdout); \
			g_stdout->ft_printf_ret = ft_printf(string, __VA_ARGS__); \
			strdout_save_ft_printf_output(g_stdout); \
			strdout_del(g_stdout); \
			write(1, "\n==\n", 4); \
			write(1, g_stdout->printf_out, strlen(g_stdout->printf_out)); \
			write(1, g_stdout->ft_printf_out, strlen(g_stdout->ft_printf_out)); \
			write(1, "\n==\n", 4); \
			assert(strcmp(g_stdout->ft_printf_out, g_stdout->printf_out) == 0);

// #define assert_printf(string, ...)	fflush(stdout);						\
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
// 										assert(ret1 == ret2 && strcmp(out1, out2) == 0);
										

#endif
