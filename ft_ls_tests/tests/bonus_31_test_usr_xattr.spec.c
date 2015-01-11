#include <project.h>

static char *cmd;
static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	cmd = "-alR /usr/bin";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-tla /usr";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_31_test_usr_xattr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);

}
