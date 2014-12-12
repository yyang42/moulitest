#include <project.h>

UT_TEST(bonus_09_test_opt_f)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch a B");

	cmd = "-1f";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-fl";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
