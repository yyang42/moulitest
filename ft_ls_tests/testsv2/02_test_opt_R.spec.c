#include <project.h>

UT_TEST(02_test_opt_R)
{
	char *cmd = "-1R";

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p level1_{1..3}/level2_{6..8}/level3_{11..13}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir -p .a .b .c && mkdir -p a b c ");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir a b c");
	sandbox_cmd("chmod 000 b");

	cmd = "-1R 2>&1 | grep -v denied";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1R 2>&1 | grep denied | wc -l | tr -d ' ' | tr -d '\n'";
	UT_ASSERT(strcmp(ft_ls(cmd), "1") == 0);

	reset_sandbox();
	sandbox_cmd("mkdir A");
	sandbox_cmd("touch A/file");
	cmd = "-1R A a";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir A");
	sandbox_cmd("touch A/file rootfile");
	cmd = "-1R A a rootfile";
/*	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");*/
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
