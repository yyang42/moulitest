#include <project.h>

UT_TEST(03_test_sorted)
{
	char *cmd = "-1";

	reset_sandbox();
	sandbox_cmd("touch a b c AA BB CC");
	UT_ASSERT(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p a b c AA BB CC");
	UT_ASSERT(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p da db dc dAA dBB dCC && touch fa fb fc fAA fBB fCC");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
