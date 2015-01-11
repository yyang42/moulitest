#include <project.h>

UT_TEST(bonus_30_test_xattr)
{
	char *cmd = "-l";

	reset_sandbox();
	sandbox_cmd("touch file && xattr -w theAnswerIs42 whatever_you_want file");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n===================\n");
	printf("%s", ls(cmd));
	printf("\n===================\n");
	printf("%s", ft_ls(cmd));
	printf("\n===================\n");

	*/
}
