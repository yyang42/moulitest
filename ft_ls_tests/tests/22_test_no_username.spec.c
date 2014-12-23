#include <project.h>

UT_TEST(22_test_no_username)
{
	char *cmd;

	reset_sandbox();
	cmd = "-l /usr/local/bin/node";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}