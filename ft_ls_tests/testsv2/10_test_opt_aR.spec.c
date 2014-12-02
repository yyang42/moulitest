#include <project.h>

UT_TEST(10_test_opt_aR)
{
	char *cmd = "-1aR";

	reset_sandbox();
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir aRdir1 .aRhdir1");
	sandbox_cmd("touch .aRhdir1/file1 .aRhdir1/.hfile1");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}