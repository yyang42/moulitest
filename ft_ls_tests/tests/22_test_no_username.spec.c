#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	cmd = "-l /usr/local/bin/node";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_22_test_no_username(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);

}