/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 10:22:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 13:47:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Project wide utility functions goes here
*/

#include <fw.h>
#include <stdio.h>
#include <mt_xstdio.h>
#include <stdbool.h>
#include <color.h>

#define MT_MAX_CMD_LENGTH 100 * 1000
#define SANDBOX_PATH "sandbox"
#define OUTPUT_AFTER_FILTER_FILE_PATH SANDBOX_PATH"/output_test"
#define RAW_OUTPUT_PATH SANDBOX_PATH"/output_raw"

void mt_assert_sh(t_test *test, char *commands, char *assert_filter)
{
	char generate_raw_cmd[MT_MAX_CMD_LENGTH];
	char filter_cmd[MT_MAX_CMD_LENGTH];

	if (SANDBOX_PATH)
		system("rm -rf "SANDBOX_PATH);
	system("mkdir -p "SANDBOX_PATH);
	sprintf(generate_raw_cmd, "printf '%s' | "RENDU_PATH"/ft_sh1 > "RAW_OUTPUT_PATH, commands);
	sprintf(filter_cmd, "cat "RAW_OUTPUT_PATH" | %s > "OUTPUT_AFTER_FILTER_FILE_PATH, assert_filter);
	system(generate_raw_cmd);
	system(filter_cmd);
	if (test->debug)
	{
		printf("\n");
		printf(C_YELLOW"=========================================\n"C_CLEAR);
		printf(C_YELLOW"[debug] cmd passed to ft_sh\n"C_CLEAR);
		printf("%s\n", generate_raw_cmd);
		printf(C_YELLOW"[debug] test filter\n"C_CLEAR);
		printf("%s\n", filter_cmd);
		printf(C_YELLOW"[debug] raw_output content (%s)"C_CLEAR"\n", RAW_OUTPUT_PATH);
		system("cat "RAW_OUTPUT_PATH);
		printf(C_YELLOW"=========================================\n"C_CLEAR);
	}
	mt_assert(!mt_isemptyfile(OUTPUT_AFTER_FILTER_FILE_PATH));
}
