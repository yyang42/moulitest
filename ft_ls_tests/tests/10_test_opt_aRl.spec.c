#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd;

	cmd = "-lRa";
	reset_sandbox();
	sandbox_cmd("mkdir .hdir");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_10_test_opt_aRl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);

}