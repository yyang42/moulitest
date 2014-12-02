#include <project.h>

UT_TEST(05_test_opt_a)
{
	char *cmd = "-1a";

	reset_sandbox();
	sandbox_cmd("mkdir .a a");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir .hiddendir{1..10} dir{1..10} && touch .hiddenfile{1..10} file{1..10}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls("-1a"));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls("-a"));
	printf("==================\n");
	*/
}