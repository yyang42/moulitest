#include <project.h>

UT_TEST(24_test_multiple_files)
{



	char *cmd;

	reset_sandbox();
	cmd = "-1 . .";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch a b C D");
	cmd = "-1 ./ .";

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n========== ls ==========\n");
	printf(ls(cmd));
	printf("========= ft_ls ========\n");
	printf(ft_ls(cmd));
	printf("========================\n");
	*/

}
