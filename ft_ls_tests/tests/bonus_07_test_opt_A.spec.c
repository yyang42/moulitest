#include <project.h>

static char *cmd;

static void unitTest_00(t_test *test) 
{
	cmd = "-lA";
	reset_sandbox();
	sandbox_cmd("mkdir .hdir dir && touch .hfile file ");

	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-lA";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	cmd = "-lAa";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	cmd = "-laA";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_07_test_opt_A(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
}