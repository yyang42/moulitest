/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 10:22:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 17:19:37 by yyang            ###   ########.fr       */
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
#define STDOUT_FILTERED_FILE STDOUT_FILE".filtered"
#define STDERR_FILE SANDBOX_PATH"/stderr.output"
#define STDERR_FILTERED_FILE STDERR_FILE".filtered"


static void print_debug(char *generate_raw_cmd)
{
	printf("\n");
	printf(C_YELLOW"=========================================\n"C_CLEAR);
	printf(C_YELLOW"[debug] cmd passed to the tested shell\n"C_CLEAR);
	printf("%s\n", generate_raw_cmd);
	printf(C_YELLOW"[debug] raw stdout (%s)"C_CLEAR"\n", STDOUT_FILE);
	system("cat "STDOUT_FILE);
	printf(C_YELLOW"[debug] raw stderr (%s)"C_CLEAR"\n", STDERR_FILE);
	system("cat "STDERR_FILE);
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
	if (filter)
	{
		sprintf(cmd, "cat %s | %s > %s", file, filter, filter_file);
		system(cmd);
	}
	(void)test;
}

void mt_assert_sh_base(t_test *test, char *commands, char *stdout_filter, char *stderr_filter)
{
	clear_sandbox();
	generate_files(commands);
	mt_assert_output(test, STDOUT_FILE, stdout_filter);
	mt_assert_output(test, STDERR_FILE, stderr_filter);
	if (test->debug)
		print_debug(commands);
	(void)test;
}

void mt_assert_sh_stdout(t_test *test, char *commands, char *stdout_filter)
{
	mt_assert_sh_base(test, commands, stdout_filter, NULL);
	mt_assert(!mt_isemptyfile(STDOUT_FILTERED_FILE));
}

void mt_assert_sh_stderr_not_empty(t_test *test, char *commands)
{
	mt_assert_sh_base(test, commands, "grep ''", "grep ''");
	mt_assert(!mt_isemptyfile(STDERR_FILTERED_FILE));
}

void mt_assert_sh_stderr_is_empty(t_test *test, char *commands)
{
	mt_assert_sh_base(test, commands, "grep ''", "grep ''");
	mt_assert(mt_isemptyfile(STDERR_FILTERED_FILE));
}

void mt_assert_sh_stdout_not_contains(t_test *test, char *commands, char *filter)
{
	mt_assert_sh_base(test, commands, filter, NULL);
	mt_assert(mt_isemptyfile(STDOUT_FILTERED_FILE));
}
