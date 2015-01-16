#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;
	reset_sandbox();

	sandbox_cmd("touch files{0..1000}");
	cmd = "-l";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_sys_03_test_many_files(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}