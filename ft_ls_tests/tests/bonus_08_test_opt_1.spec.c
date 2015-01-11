#include <project.h>

static	char *cmd;

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file");

	cmd = "-l1";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-1l";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_08_test_opt_1(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);

}