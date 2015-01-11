#include <project.h>

static	char *cmd;

static void unitTest_00(t_test *test) 
{
	cmd = "-ARSUacdlprtu /usr/share";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-utrpldcaUSRA /usr/share";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_21_test_opt_mix_sort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
}
