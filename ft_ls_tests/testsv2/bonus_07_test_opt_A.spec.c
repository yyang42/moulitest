#include <project.h>

UT_TEST(bonus_07_test_opt_A)
{
	char *cmd;

	cmd = "-lA";
	reset_sandbox();
	sandbox_cmd("mkdir .hdir dir && touch .hfile file ");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	cmd = "-lA";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lAa";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-laA";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls("-1A"));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls("-A"));
	printf("==================\n");
	*/
}
