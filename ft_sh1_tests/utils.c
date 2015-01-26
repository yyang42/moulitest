/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 10:22:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 15:46:16 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Project wide utility functions goes here
*/

#include <fw.h>
#include <mt_xstdio.h>
#include <stdbool.h>
#include <color.h>
#include <unistd.h>

#define MT_MAX_CMD_LENGTH 100 * 1000
#define SANDBOX_PATH "sandbox"
#define OUTPUT_AFTER_FILTER_FILE_PATH SANDBOX_PATH"/output_test"
#define RAW_OUTPUT_PATH SANDBOX_PATH"/output_raw"
#define STDOUT_FILE SANDBOX_PATH"/stdout.output"
#define STDERR_FILE SANDBOX_PATH"/stderr.output"


static void print_debug(char *generate_raw_cmd, char *stdout_filter, char *stderr_filter)
{
	printf("\n");
	printf(C_YELLOW"=========================================\n"C_CLEAR);
	printf(C_YELLOW"[debug] cmd passed to ft_sh\n"C_CLEAR);
	printf("%s\n", generate_raw_cmd);
	printf(C_YELLOW"[debug] stdout_filter\n"C_CLEAR);
	printf("%s\n", stdout_filter);
	printf(C_YELLOW"[debug] stderr_filter\n"C_CLEAR);
	printf("%s\n", stderr_filter);
	printf(C_YELLOW"[debug] raw_output content (%s)"C_CLEAR"\n", STDOUT_FILE);
	system("cat "STDOUT_FILE);
	printf(C_YELLOW"=========================================\n"C_CLEAR);
}

static void clear_sandbox()
{
	if (SANDBOX_PATH)
		system("rm -rf "SANDBOX_PATH);
	system("mkdir -p "SANDBOX_PATH);
}

static void generate_files(char *commands)
{
	char final_cmd[MT_MAX_CMD_LENGTH];

	sprintf(final_cmd, "printf '%s' | "RENDU_PATH"/ft_sh1  1> "STDOUT_FILE" 2> "STDERR_FILE, commands);
	system(final_cmd);
}

void mt_assert_output(t_test *test, char *file, char *filter)
{
	char cmd[MT_MAX_CMD_LENGTH];
	char filter_file[MT_MAX_CMD_LENGTH];

	sprintf(filter_file, "%s.filtered", file);
	sprintf(cmd, "cat %s | %s > %s", file, filter, filter_file);
	system(cmd);
	if (filter)
	{
		mt_assert(!mt_isemptyfile(filter_file));
	}
	else
	{
		mt_assert(mt_isemptyfile(filter_file));
	}
}

void mt_assert_sh(t_test *test, char *commands, char *stdout_filter, char *stderr_filter)
{
	clear_sandbox();
	generate_files(commands);
	if (test->debug)
		print_debug(commands, stdout_filter, stderr_filter);
	mt_assert_output(test, STDOUT_FILE, stdout_filter);
	mt_assert_output(test, STDERR_FILE, stderr_filter);
	(void)stderr_filter;
}

// void mt_assert_sh_stderr(t_test *test, char *commands, char *assert_filter)
// {
// 	mt_assert_sh_base(test, commands, assert_filter, STDERR_FILENO);
// }
