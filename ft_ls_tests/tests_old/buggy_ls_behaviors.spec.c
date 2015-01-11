#include <project.h>

UT_TEST(buggy_ls_behaviors)
{
	UT_ASSERT(1);

	char *cmd;
	cmd = "-lR";

	reset_sandbox();

	sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");

	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1R";
	reset_sandbox();
	sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir .dir1A .dir1B && mkdir .dir1A/dir2A && touch .dir1A/dir2A/file3");
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir .dir1A .dir1B && mkdir .dir1A/dir2{A,B} && touch .dir1A/dir2A/file3A");
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}