#include <project.h>

UT_TEST(15_test_hyphen_harder)
{
	char *cmd;
	reset_sandbox();
	sandbox_cmd("touch -- - -- ---");

	cmd = "-1 -- -- --";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 - - -";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 -- - -- ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 - -- ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 -- - ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -- - -- ---");

	cmd = "-1 -- -- --";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 - - -";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 -- - -- ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 - -- ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1 -- - ---";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

}
