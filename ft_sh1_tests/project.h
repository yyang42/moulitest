/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 00:54:40 by celegran          #+#    #+#             */
/*   Updated: 2015/02/02 22:33:32 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Project headers
*/

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>

#define MT_MAX_CMD_LENGTH 100 * 1000
#define SANDBOX_PATH "sandbox"
#define OUTPUT_AFTER_FILTER_FILE_PATH SANDBOX_PATH"/output_test"
#define RAW_OUTPUT_PATH SANDBOX_PATH"/output_raw"
#define STDOUT_FILE SANDBOX_PATH"/stdout.output"
#define STDOUT_FILTERED_FILE STDOUT_FILE".filtered"
#define STDERR_FILE SANDBOX_PATH"/stderr.output"
#define STDERR_FILTERED_FILE STDERR_FILE".filtered"
<<<<<<< HEAD
=======
#define EXECUTABLE_NAME "ft_minishell1"
>>>>>>> fcfb2f2cc8e7bbe306aa0ff3e13b02036eecfcbb

void mt_assert_sh_stdout(t_test *test, char *commands, char *stdout_filter);
void mt_assert_sh_stderr_not_empty(t_test *test, char *commands);
void mt_assert_sh_stderr_is_empty(t_test *test, char *commands);
void mt_assert_sh_stdout_not_contains(t_test *test, char *commands, char *filter);

#endif
