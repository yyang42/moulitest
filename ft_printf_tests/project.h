/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/27 10:36:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>
# include <capture.h>

int		ft_printf(const char *format, ...);
char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

t_cap_stdout *cap;
char *printf_out;
char *ft_printf_out;

#define assert_printf(arg1, ...) \
	cap = capture_stdout_create(STDOUT_FILENO); \
	capture_stdout(cap); \
  	printf(arg1, __VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer(cap)); \
  	ft_printf(arg1, __VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer(cap)); \
	capture_stdout_destroy(cap); \
	assert(strcmp(printf_out, ft_printf_out) == 0); \
	free(printf_out); \
	free(ft_printf_out)

#endif
