#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	cmd = "-l /etc";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_sys_02_test_etc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}