#include <project.h>

UT_TEST(01_test_without_opt)
{
	char *cmd;

	cmd = "-1";
	reset_sandbox();
	sandbox_cmd("touch aaa bbb ccc");
	UT_ASSERT(strcmp(ft_ls(cmd), "aaa\nbbb\nccc\n") == 0);

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	// cmd = "";
	// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
