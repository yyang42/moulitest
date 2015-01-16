#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;
	reset_sandbox();

	cmd = "-l /var/run";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_sys_04_test_var_run(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}