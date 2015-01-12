#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 . .";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch a b C D");
	cmd = "-1 ./ .";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);;
}

static void unitTest_02(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch a c z");
	sandbox_cmd("mkdir b d");
	sandbox_cmd("ln -s a e && ln -s a f");
	cmd = "-1 z b a c d f e";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_24_test_multiple_files(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
}