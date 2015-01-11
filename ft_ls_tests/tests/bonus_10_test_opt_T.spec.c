#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch file");

	cmd = "-Tl";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_10_test_opt_T(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}