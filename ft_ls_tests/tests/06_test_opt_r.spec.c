#include <project.h>

UT_TEST(06_test_opt_r)
{
	char *cmd = "-1r";

	reset_sandbox();
	sandbox_cmd("touch a b c AA BB CC");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p a b c AA BB CC");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p POP mok POPO liu && touch PIP mik PIPI lui");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls("-1r"));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls("-r"));
	printf("==================\n");
	*/
}
