#include <project.h>

UT_TEST(bonus_11_test_opt_g)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch file");

	cmd = "-g";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1g";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-g1";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
