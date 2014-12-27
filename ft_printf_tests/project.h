/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2014/12/27 19:55:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>
# include <capture.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_printf_to_str(char *format, ...);
char	*printf_to_str(char *format, ...);

int		debug;
t_cap_stdout *cap;
char *printf_out;
char *ft_printf_out;

#define debug_on() debug = 1;
#define debug_off() debug = 0;

#define assert_printf(arg1, ...) \
	cap = capture_stdout_create(STDOUT_FILENO); \
	capture_stdout(cap); \
  	printf(arg1, __VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer(cap)); \
  	ft_printf(arg1, __VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer(cap)); \
	capture_stdout_destroy(cap); \
	if (debug) \
	{ \
		printf("\nft_printf_out: %s\n", ft_printf_out); \
		printf("printf_out:    %s\n", printf_out); \
	} \
	assert(strcmp(printf_out, ft_printf_out) == 0); \
	free(printf_out); \
	free(ft_printf_out)

#define assert_printf_noarg(arg1) \
	cap = capture_stdout_create(STDOUT_FILENO); \
	capture_stdout(cap); \
  	printf(arg1); \
	printf_out = strdup(capture_stdout_get_buffer(cap)); \
  	ft_printf(arg1); \
	ft_printf_out = strdup(capture_stdout_get_buffer(cap)); \
	capture_stdout_destroy(cap); \
	if (debug) \
	{ \
		printf("\nft_printf_out: %s\n", ft_printf_out); \
		printf("printf_out:    %s\n", printf_out); \
	} \
	assert(strcmp(printf_out, ft_printf_out) == 0); \
	free(printf_out); \
	free(ft_printf_out)

#endif
