#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1r";

	reset_sandbox();
	sandbox_cmd("touch a b c AA BB CC");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1r";

	reset_sandbox();
	sandbox_cmd("mkdir -p a b c AA BB CC");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-1r";

	reset_sandbox();
	sandbox_cmd("mkdir -p POP mok POPO liu && touch PIP mik PIPI lui");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_05_test_opt_r(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
}