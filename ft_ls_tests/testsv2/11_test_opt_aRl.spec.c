#include <project.h>

UT_TEST(11_test_opt_aRl)
{
	char *cmd;

	cmd = "-lRa";
	reset_sandbox();
	sandbox_cmd("mkdir .hdir");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}