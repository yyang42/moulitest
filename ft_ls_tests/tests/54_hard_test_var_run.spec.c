#include <project.h>

UT_TEST(54_hard_test_var_run)
{
	char *cmd;
	reset_sandbox();

	cmd = "-l /var/run";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	// cmd = "-1 /etc";
	// printf("\n========== ls ==========\n");
	// printf(ls(cmd));
	// printf("========= ft_ls ========\n");
	// printf(ft_ls(cmd));
	// printf("========================\n");
	// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}