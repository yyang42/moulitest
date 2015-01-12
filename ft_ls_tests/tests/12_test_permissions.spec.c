#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd;

	cmd = "-l";
	reset_sandbox();
	sandbox_cmd("touch a b c");
	sandbox_cmd("chmod 644 a");
	sandbox_cmd("chmod 755 b");
	sandbox_cmd("chmod 311 c");

	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd;

	cmd = "-l";
	reset_sandbox();
	sandbox_cmd("mkdir a b c");
	sandbox_cmd("chmod 644 a");
	sandbox_cmd("chmod 755 b");
	sandbox_cmd("chmod 311 c");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_12_test_permissions(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);

}