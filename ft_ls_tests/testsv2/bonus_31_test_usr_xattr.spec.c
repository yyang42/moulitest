#include <project.h>

UT_TEST(bonus_31_test_usr_xattr)
{
	reset_sandbox();
	char *cmd;

	cmd = "-alR /usr/bin";
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-tla /usr";
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n========== ls ==========\n");
	printf(ls(cmd));
	printf("========= ft_ls ========\n");
	printf(ft_ls(cmd));
	printf("========================\n");
	*/
}
