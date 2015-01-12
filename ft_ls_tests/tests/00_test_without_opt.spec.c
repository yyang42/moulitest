#include <project.h>

static void simple_test(t_test *test)
{
	char *cmd;

	cmd = "-1";
	reset_sandbox();
	sandbox_cmd("touch aaa bbb ccc");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ft_ls(cmd), "aaa\nbbb\nccc\n") == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd;

	cmd = "-1";
	reset_sandbox();
	sandbox_cmd("touch - file");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd;

	cmd = "-1";
	reset_sandbox();
	sandbox_cmd("mkdir - dir");

	cmd = "-1 -- - dir";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_00_test_without_opt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
}
