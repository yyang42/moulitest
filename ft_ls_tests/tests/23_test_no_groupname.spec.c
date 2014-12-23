#include <project.h>

UT_TEST(23_test_no_groupname)
{



	char *cmd;

	reset_sandbox();
	cmd = "-l /usr/share/doc";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n========== ls ==========\n");
	printf(ls(cmd));
	printf("========= ft_ls ========\n");
	printf(ft_ls(cmd));
	printf("========================\n");
	*/

}
