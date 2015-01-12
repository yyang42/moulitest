#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1rR";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1rR";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-1rR";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..3}/level2_{6..8}/level3_{11..13}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd = "-1rR";

	reset_sandbox();
	sandbox_cmd("mkdir -p .a .b .c && mkdir -p a b c ");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_06_test_opt_rR(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
}