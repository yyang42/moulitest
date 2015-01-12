#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1R";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1R";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..3}/level2_{6..8}/level3_{11..13}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-1R";

	reset_sandbox();
	sandbox_cmd("mkdir -p .a .b .c && mkdir -p a b c ");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("mkdir a b c");
	sandbox_cmd("chmod 000 b");

	cmd = "-1R 2>&1 | grep -v denied";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_4(t_test *test)
{
	char *cmd;

	cmd = "-1R 2>&1 | grep denied | wc -l | tr -d ' ' | tr -d '\n'";
	mt_assert(strcmp(ft_ls(cmd), "1") == 0);
}

static void simple_test_5(t_test *test)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("mkdir A");
	sandbox_cmd("touch A/file");
	cmd = "-1R A a";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_6(t_test *test)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("mkdir A");
	sandbox_cmd("touch A/file rootfile");
	cmd = "-1R A a rootfile";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_01_test_opt_R(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
	SUITE_ADD_TEST(suite, simple_test_4);
	SUITE_ADD_TEST(suite, simple_test_5);
	SUITE_ADD_TEST(suite, simple_test_6);
}