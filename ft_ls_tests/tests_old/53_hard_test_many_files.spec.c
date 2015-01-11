#include <project.h>

UT_TEST(53_hard_test_many_files)
{
	char *cmd;
	reset_sandbox();


	sandbox_cmd("touch files{0..1000}");
	cmd = "-l";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	// printf("\n========== ls ==========\n");
	// printf(ls(cmd));
	// printf("========= ft_ls ========\n");
	// printf(ft_ls(cmd));
	// printf("========================\n");
}
