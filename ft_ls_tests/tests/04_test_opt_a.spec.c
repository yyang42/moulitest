#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1a";

	reset_sandbox();
	sandbox_cmd("mkdir .a a");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1a";

	reset_sandbox();
	sandbox_cmd("mkdir .hiddendir{1..10} dir{1..10} && touch .hiddenfile{1..10} file{1..10}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_04_test_opt_a(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
}