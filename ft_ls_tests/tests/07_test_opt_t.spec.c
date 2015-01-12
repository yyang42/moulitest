#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1t";

	reset_sandbox();
	sandbox_cmd("touch a b c d e && touch -t 201212101830.55 c");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1t";

	reset_sandbox();
	sandbox_cmd("touch -t 201312101830.55 a && touch -t 201212101830.55 b && touch -t 201412101830.55 c");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-1t";

	reset_sandbox();
	sandbox_cmd("touch fileA{1..5} fileB{1..5} fileC{1..5} && touch -t 200012101830.55 fileA{1..5}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd = "-1t";

	cmd = "-1lt";
	reset_sandbox();
	sandbox_cmd("touch -t 201312101830.55 a");
	sandbox_cmd("touch -t 201212101830.55 b");
	sandbox_cmd("touch -t 201412101830.55 c");
	sandbox_cmd("touch -t 201411221830.55 d");
	sandbox_cmd("touch -t 201405212033.55 e");
	sandbox_cmd("touch -t 201409221830.55 f");
	sandbox_cmd("touch -t 202007221830.55 g");
	sandbox_cmd("touch -t 300012101830.55 h");

	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_4(t_test *test)
{
	char *cmd = "-1t";

	cmd = "-1lt";
	reset_sandbox();
	sandbox_cmd("touch -t 200012101830.55 a");
	sandbox_cmd("touch -t 201412101830.55 b");
	sandbox_cmd("ln b d");
	sandbox_cmd("ln -s c e");
	sandbox_cmd("ln -s a f");
	sandbox_cmd("touch -t 300012101830.55 c");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_5(t_test *test)
{
	char *cmd = "-1t";

	cmd = "-1lt";
	reset_sandbox();

	sandbox_cmd("touch -t 201312101830.55 B");
	sandbox_cmd("touch -t 201312101830.55 a");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_07_test_opt_t(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
	SUITE_ADD_TEST(suite, simple_test_4);
	SUITE_ADD_TEST(suite, simple_test_5);
}