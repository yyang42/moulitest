#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1aR";

	reset_sandbox();
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd = "-1aR";

	reset_sandbox();
	sandbox_cmd("mkdir aRdir1 .aRhdir1");
	sandbox_cmd("touch .aRhdir1/file1 .aRhdir1/.hfile1");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_09_test_opt_aR(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);

}