#include <project.h>

UT_TEST(bonus_32_test_ACL)
{
	char *cmd = "-l /";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	/*
	printf("\n===================\n");
	printf("%s", ls(cmd));
	printf("\n===================\n");
	printf("%s", ft_ls(cmd));
	printf("\n===================\n");

	*/
}
