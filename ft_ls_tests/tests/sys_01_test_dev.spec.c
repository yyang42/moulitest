#include <project.h>

static char *cmd;

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	cmd = "-1 /dev";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-1l /dev | grep -v io8 | grep -v autofs_nowait | sed -E \"s/ +/ /g\"";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	cmd = "-1la /dev | grep -v io8 | grep -v autofs_nowait | sed -E \"s/ +/ /g\"";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_sys_01_test_dev(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
}