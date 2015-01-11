#include <project.h>

static	char *cmd;

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch a B");

	cmd = "-1f";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-fl";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_09_test_opt_f(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
}