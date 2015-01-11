#include <project.h>

static	char *cmd = "-1Aa";

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir .a a");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir .hiddendir{1..10} dir{1..10} && touch .hiddenfile{1..10} file{1..10}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_20_test_opt_comb_aA(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
}
