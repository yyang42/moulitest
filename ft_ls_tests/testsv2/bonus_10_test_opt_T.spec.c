#include <project.h>

UT_TEST(bonus_10_test_opt_T)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch file");

	cmd = "-Tl";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
