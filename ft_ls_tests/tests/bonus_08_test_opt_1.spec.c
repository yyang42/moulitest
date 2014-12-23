#include <project.h>

UT_TEST(bonus_08_test_opt_1)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch file");

	cmd = "-l1";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1l";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls("-1A"));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls("-A"));
	printf("==================\n");
	*/
}
