/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2015/01/02 18:05:14 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>
# include <capture.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *format, ...);
char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

int		debug;
t_cap_stdout cap;
char *printf_out;
int printf_ret;
char *ft_printf_out;
int ft_printf_ret;

// #define debug_next_assert() debug = 1;
// #define debug_off() debug = 0;

#define debug_output

#define assert_printf(arg1, ...) \
	capture_stdout(); \
  	printf_ret = printf(arg1, __VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer()); \
	if (test->debug) \
	{ \
		fprintf(stderr, "\nTEST: %s\n", test->name); \
		fprintf(stderr, "=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
  	ft_printf_ret = ft_printf(arg1, __VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer()); \
	capture_stdout_destroy(); \
	if (test->debug) \
	{ \
		fprintf(stderr,   "\n===== ft_printf_out =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
	assert(strcmp(printf_out, ft_printf_out) == 0); \
	assert(printf_ret == ft_printf_ret); \
	free(printf_out); \
	free(ft_printf_out)

#define assert_printf_noarg(arg1) assert_printf(arg1, NULL)
/*
	capture_stdout(); \
  	printf_ret = printf(arg1); \
	printf_out = strdup(capture_stdout_get_buffer()); \
	if (test->debug) \
	{ \
		printf("\n=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out); \
		printf(  "=========================\n"); \
	} \
  	ft_printf_ret = ft_printf(arg1); \
	ft_printf_out = strdup(capture_stdout_get_buffer()); \
	capture_stdout_destroy(); \
	if (test->debug) \
	{ \
		printf(  "===== ft_printf_out =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out); \
		printf(  "=========================\n"); \
	} \
	assert(strcmp(printf_out, ft_printf_out) == 0); \
	assert(printf_ret == ft_printf_ret); \
	free(printf_out); \
	free(ft_printf_out)
*/
#endif
