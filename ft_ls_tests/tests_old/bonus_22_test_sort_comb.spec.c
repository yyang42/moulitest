#include <project.h>

UT_TEST(bonus_22_test_sort_comb)
{
	reset_sandbox();
	char *cmd;

	cmd = "-lUc  ..";

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lcu  ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-luc  ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lcU  ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tUc ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tcu ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tuc ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tcU ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-tlUc ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-tlcu ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-tluc ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-tlcU ..";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
