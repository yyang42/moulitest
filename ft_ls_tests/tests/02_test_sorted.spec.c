#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1";

	reset_sandbox();
	sandbox_cmd("touch a b c AA BB CC");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1";

	reset_sandbox();
	sandbox_cmd("mkdir -p a b c AA BB CC");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-1";

	reset_sandbox();
	sandbox_cmd("mkdir -p da db dc dAA dBB dCC && touch fa fb fc fAA fBB fCC");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_02_test_sorted(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);

}